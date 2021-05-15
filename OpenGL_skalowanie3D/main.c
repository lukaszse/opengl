#include <DevGL\gl.h>
#include <DevGL\glu.h>
#include <DevGL\glut.h>
#include <DevGL\glaux.h>

float sx = 1.0;
float sy = 1.0;

void my_display()
{
    glClear(GL_COLOR_BUFFER_BIT);               /* Wyczyszczenie ekranu. */

    glMatrixMode(GL_PROJECTION);                /* Ustawienie macierzy w tryb projekcji. */
    glLoadIdentity();                           /* Zaladowanie macierzy jednostkowej. */
    gluPerspective(60.0, 1.0, 1.0, 1000.0);     /* Utworzenie macierzy rzutowania perspektywicznego. */

    glMatrixMode(GL_MODELVIEW);                 /* Ustawienie macierzy w tryb modelowania. */
    glLoadIdentity();                           /* Zaladowanie macierzy jednostkowej. */

    glScalef(sx, sy, 1.0);                      /* Zdefiniowanie macierzy skalowania. */
    glTranslatef(0.0, 0.0, -500.0);             /* Zdefiniowanie macierzy translacji. */

    glColor3f(1.0, 1.0, 0.0);
    glutWireSphere(40, 15, 15);                 /* Zdefiniowanie kwadryki reprezentujacej sfere. */

    sx += 0.0001;
    sy += 0.0001;

    glutSwapBuffers();                          /* Przelaczenie buforow. */
}

void my_keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 27:
            exit(0);
            break;
        default:
            break;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("OpenGL. Transformacje 3D");

    glutKeyboardFunc(my_keyboard);
    glutDisplayFunc(my_display);
    glutIdleFunc(my_display);
    glutMainLoop();
}
