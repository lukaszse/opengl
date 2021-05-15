#include <DevGL\gl.h>
#include <DevGL\glu.h>
#include <DevGL\glut.h>
#include <DevGL\glaux.h>

float tx = -180.0;
float ty = -180.0;
float angle = 0.0;

void my_display()
{
    glClear(GL_COLOR_BUFFER_BIT);               /* Wyczyszczenie ekranu. */

    glMatrixMode(GL_PROJECTION);                /* Ustawienie macierzy w tryb projekcji. */
    glLoadIdentity();                           /* Zaladowanie macierzy jednostkowej. */
    gluPerspective(60.0, 1.0, 1.0, 1000.0);     /* Utworzenie macierzy rzutowania perspektywicznego. */

    glMatrixMode(GL_MODELVIEW);                 /* Ustawienie macierzy w tryb modelowania. */
    glLoadIdentity();                           /* Zaladowanie macierzy jednostkowej. */
    glTranslatef(tx, 0.0, -200.0);              /* Translacja obiektu na osi X i Z. */
    glRotatef(angle, 0.0, 1.0, 0.0);            /* Obrót o kat angle wzgledem osi Y. */

    glColor3f(1.0, 1.0, 0.0);
    glutWireSphere(40, 15, 15);                 /* Zdefiniowanie kwadryki reprezentujacej sfere. */

    glLoadIdentity();                           /* Zaladowanie macierzy jednostkowej. */
    glTranslatef(0.0, ty, -200.0);              /* Translacja obiektu na osi Y i Z. */
    glRotatef(angle * 2, 1.0, 0.0, 0.0);        /* Obrót o kat angle wzglêdem osi X. */

    glColor3f(1.0, 0.0, 0.0);
    glutWireSphere(40, 15, 15);

    tx += 0.01;
    ty += 0.006;
    angle += 0.01;

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
