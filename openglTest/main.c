#include <gl.h>
#include <glu.h>
#include <glut.h>

float AngleX=0.0;
float AngleY=0.0;
float AngleZ=0.0;

void my_display()
{   
  glClear(GL_COLOR_BUFFER_BIT);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, 1.0, 1.0, 250.0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glTranslatef(0.0, 0.0, -20.0);
  glRotatef(AngleX, 1.0, 0.0, 0.0);
  glRotatef(AngleY, 0.0, 1.0, 0.0);
  glRotatef(AngleZ, 0.0, 0.0, 1.0);

  //glutWireTeapot(5.0);
  glutWireCube(6);

  AngleY+=0.1;
  AngleX+=0.1;
  AngleZ+=0.1;

  glutSwapBuffers();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(0,0);
  glutCreateWindow("OpenGL test");

  glutDisplayFunc(my_display);
  glutIdleFunc(my_display);
  glutMainLoop();
}

