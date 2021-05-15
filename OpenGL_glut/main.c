#include <DevGL\gl.h>
#include <DevGL\glu.h>
#include <DevGL\glut.h>
#include <DevGL\glaux.h>

float tx = 0.0, ty = 0.0;

void my_display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(tx, ty, 0);

    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.9,-0.9);
    glVertex2f(-0.9,-0.5);
    glVertex2f(-0.5,-0.5);
    glVertex2f(-0.5,-0.9);
    glEnd();

    glutSwapBuffers();
}

void specialKey(unsigned char key, int x, int y){
    switch (key) {
        case GLUT_KEY_UP:
            ty += 0.1;
            break;
        case GLUT_KEY_DOWN:
            ty -= 0.1;
            break;
        case GLUT_KEY_RIGHT:
            tx += 0.1;
            break;
        case GLUT_KEY_LEFT:
            tx -= 0.1;
            break;
    }
}

void my_key(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 27:
            exit(0);
        default:
            break;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("OpenGL + GLUT");
    glutDisplayFunc(my_display);
    glutKeyboardFunc(my_key);
    glutSpecialFunc(specialKey);
    glutIdleFunc(my_display);
    glutMainLoop();

}