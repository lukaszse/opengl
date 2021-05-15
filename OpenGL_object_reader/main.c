#pragma pack(1)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <GL\gl.h>
#include <GL\glu.h>
#include <GL\glut.h>

typedef struct _Vector3D {
  float x, y, z;
}Vector3D;

typedef struct _Face {
  int  a, b, c;
}Face;

int      numberVertices;
Vector3D *VertexesArray;

int      numberFaces;
Face     *FacesArray;

Vector3D *NormalsToFaceArray;
Vector3D *NormalsToVertexArray;

float   AngleX = 0.0;
float   AngleY = 0.0;
float   AngleZ = 0.0;
    
void LoadObject(char *filename) {
    FILE *file;
    char line[255], *str;   
    int iVertex = 0, iFace = 0;
    
    file = fopen(filename, "r");
    numberVertices = 0;
    numberFaces = 0;
    while (!feof(file))
    {
        fgets(line, 255, file);
        if (strncmp(line, "v ", 2) == 0)
            numberVertices++;
        if (line[0] == 'f')
            numberFaces++;
    }                              
    
    fseek(file, 0, SEEK_SET); 
    if ((numberVertices > 0) && (numberFaces > 0))
    {
        VertexesArray = calloc(numberVertices, sizeof(Vector3D));
        FacesArray = calloc(numberFaces, sizeof(Face));
        while (!feof(file))
        {
            fgets(line, 255, file);
            if (strncmp(line, "v ", 2) == 0)
            {
                str = strtok(line, " ");            
                VertexesArray[iVertex].x = atof(strtok(NULL, " "));
                VertexesArray[iVertex].y = atof(strtok(NULL, " "));
                VertexesArray[iVertex].z = atof(strtok(NULL, " "));                 
                /*printf("%6.3f %6.3f %6.3f\n", VertexesArray[iVertex].x, VertexesArray[iVertex].y, VertexesArray[iVertex].z);*/
                iVertex++;
            }
            if (line[0] == 'f')
            {
                str = strtok(line, " ");            
                FacesArray[iFace].a = atoi(strtok(NULL, " ")) - 1;
                FacesArray[iFace].b = atoi(strtok(NULL, " ")) - 1;
                FacesArray[iFace].c = atoi(strtok(NULL, " ")) - 1;
                /*printf("%d %d %d\n", FacesArray[iFace].a, FacesArray[iFace].b, FacesArray[iFace].c);*/
                iFace++;
            }
            strcpy(line, "");
        }       
    }           
    fclose(file);
}
void NormalizeVertexes(double _MAX, double _MIN) {
    int             i, j;
    float           x, y, z;
    float           xm, ym, zm;
    float           xmax, ymax, zmax;
    float           xmin, ymin, zmin;
    float           _xmax, _ymax, _zmax;
    float           _xmin, _ymin, _zmin;

    xmax=-1000000000.0;
    xmin= 1000000000.0;
    ymax=-1000000000.0;
    ymin= 1000000000.0;
    zmax=-1000000000.0;
    zmin= 1000000000.0;

    for (i = 0; i < numberVertices; i++)
    {
        x = VertexesArray[i].x;
        y = VertexesArray[i].y;
        z = VertexesArray[i].z;
        
        if (x > xmax) xmax=x;
        if (y > ymax) ymax=y;
        if (z > zmax) zmax=z;
        if (x < xmin) xmin=x;
        if (y < ymin) ymin=y;
        if (z < zmin) zmin=z;
    }

    if (xmax == xmin)
    {
        xmax += 0.001;
        xmin -= 0.001;
    }
    if (ymax == ymin)
    {
        ymax += 0.001;
        ymin -= 0.001;
    }
    if (zmax==zmin)
    {
        zmax += 0.001;
        zmin -= 0.001;
    }
    
    xm = xmax - xmin;
    ym = ymax - ymin;
    zm = zmax - zmin;

    xm /= 2.0;
    ym /= 2.0;
    zm /= 2.0;

    for (i = 0; i < numberVertices; i++)
    {
        VertexesArray[i].x = (VertexesArray[i].x - xmax) + xm;
        VertexesArray[i].y = (VertexesArray[i].y - ymax) + ym;
        VertexesArray[i].z = (VertexesArray[i].z - zmax) + zm;
    }

    xmin = -xm;
    xmax = xm;
    ymin = -ym;
    ymax = ym;
    zmin = -zm;
    zmax = zm;

    _xmax = _MAX;
    _xmin = _MIN;
    _ymax = (_MAX * ymax) / xmax;
    _ymin = (_MIN * ymin) / xmin;
    _zmax = (_MAX * zmax) / xmax;
    _zmin = (_MIN * zmin) / xmin;

    if ((ym > xm) && (ym > zm))
    {
        _xmax = (_MAX * xmax) / ymax;
        _xmin = (_MIN * xmin) / ymin;
        _ymax = _MAX;
        _ymin = _MIN;
        _zmax = (_MAX * zmax) / ymax;
        _zmin = (_MIN * zmin) / ymin;
    }
    
    if ((zm > xm) && (zm > ym))
    {
        _xmax = (_MAX * xmax) / zmax;
        _xmin = (_MIN * xmin) / zmin;
        _ymax = (_MAX * ymax) / zmax;
        _ymin = (_MIN * ymin) / zmin;
        _zmax = _MAX;
        _zmin = _MIN;
    }

    for (i = 0; i < numberVertices; i++)
    {
        VertexesArray[i].x = ((VertexesArray[i].x - xmin) / (xmax - xmin)) * (_xmax - _xmin) + _xmin;
        VertexesArray[i].y = ((VertexesArray[i].y - ymin) / (ymax - ymin)) * (_ymax - _ymin) + _ymin;
        VertexesArray[i].z = ((VertexesArray[i].z - zmin) / (zmax - zmin)) * (_zmax - _zmin) + _zmin;
    }
}

void ComputeNormalsToFace()
{
}

void ComputeNormalsToVertex()
{
}


void my_display() {
    int     i;
    int     a, b, c;
    float   x1, y1, z1, x2, y2, z2, x3, y3, z3;
    
    //////////////////////////////////////////////////////////  
    float            light_pos[4]={0.0, 0.0, -100.0, 0.0};

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);

    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
    //////////////////////////////////////////////////////////  
    
    glPushMatrix();
    
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0, 1.0, 250.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0, 0.0, -20.0);
    glRotatef(AngleX, 1.0, 0.0, 0.0);
    glRotatef(AngleY, 0.0, 1.0, 0.0);
    glRotatef(AngleZ, 0.0, 0.0, 1.0);
 
    srand(0);
    for (i = 0; i < numberFaces; i++)
    {
        a = FacesArray[i].a;
        b = FacesArray[i].b;
        c = FacesArray[i].c;

        x1 = VertexesArray[a].x;
        y1 = VertexesArray[a].y;
        z1 = VertexesArray[a].z;

        x2 = VertexesArray[b].x;
        y2 = VertexesArray[b].y;
        z2 = VertexesArray[b].z;

        x3 = VertexesArray[c].x;
        y3 = VertexesArray[c].y;
        z3 = VertexesArray[c].z;

        /*glColor3ub(255, 255, 255);
        glPointSize(4.0);
        glBegin(GL_POINTS);
            glVertex3f(x1, y1, z1);
            glVertex3f(x2, y2, z2);
            glVertex3f(x3, y3, z3);
        glEnd();*/

        /*glColor3ub(255, 255, 255);
        glLineWidth(3.0);
        glBegin(GL_LINE_STRIP);
            glVertex3f(x1, y1, z1);
            glVertex3f(x2, y2, z2);
            glVertex3f(x3, y3, z3);
        glEnd();*/        

        /*glColor3ub(rand()%255, rand()%255, rand()%255);
        glBegin(GL_TRIANGLES);
            glVertex3f(x1, y1, z1);
            glVertex3f(x2, y2, z2);
            glVertex3f(x3, y3, z3);
        glEnd();*/
        
        /* Cieniowanie FLAT. */
        /*glShadeModel(GL_FLAT);
        Vector3D n;
        n = NormalsToFace[i];
        glBegin(GL_TRIANGLES);
            glNormal3f(n.x, n.y, n.z);
            glVertex3f(x1, y1, z1);
            glVertex3f(x2, y2, z2);
            glVertex3f(x3, y3, z3);
        glEnd();*/  
        
        /* Cieniowanie Gourauda. */
        glShadeModel(GL_SMOOTH);
        Vector3D n1, n2, n3;
        n1 = NormalsToVertexArray[a];
        n2 = NormalsToVertexArray[b];
        n3 = NormalsToVertexArray[c];
        glBegin(GL_TRIANGLES);
            glNormal3f(n1.x, n1.y, n1.z);
            glVertex3f(x1, y1, z1);
            glNormal3f(n2.x, n2.y, n2.z);
            glVertex3f(x2, y2, z2);
            glNormal3f(n3.x, n3.y, n3.z);
            glVertex3f(x3, y3, z3);
        glEnd();       
    }

    glPopMatrix();

    AngleX += 0.05;
    AngleY += 0.05;
    AngleZ += 0.05; 
  
    glutSwapBuffers();  
}
void keyboard(unsigned char key, int x, int y) {
    switch(key)
    {
        case 32:
            break;    
        case 27:
            exit(0);
            break;
        default:
            break;
    }
}
int main(int argc, char *argv[]) {
    
    LoadObject("teapot.obj");
    NormalizeVertexes(10.0, -10.0);
    
    ComputeNormalsToFace();
    ComputeNormalsToVertex();
        
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(0,0);
    glutCreateWindow("OpenGL + GLUT");
    glutDisplayFunc(my_display);
    glutIdleFunc(my_display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}

