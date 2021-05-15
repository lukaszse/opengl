#include <DevGL\gl.h>
#include <DevGL\glu.h>
#include <DevGL\glut.h>

float angle1 = 0.0;
float angle2 = 0.0;

void my_display()
{
    glClear(GL_COLOR_BUFFER_BIT);               /* must have Wyczyszczenie ekranu. */
    glMatrixMode(GL_PROJECTION);                /* Ustawienie macierzy w tryb projekcji. */
    glLoadIdentity();                           /* must have Zaladowanie macierzy jednostkowej. */

    gluPerspective(60.0, 1.0, 1.0, 1000.0);     /* Utworzenie macierzy rzutowania perspektywicznego. */

    glMatrixMode(GL_MODELVIEW);                 /* Ustawienie macierzy w tryb modelowania. */
    glLoadIdentity();                           /* Zaladowanie macierzy jednostkowej. */

    // żółta
    glTranslatef(0, 0.0, -200);             /* Translacja obiektu na osi Z. */
    glRotatef(angle1, 0.0, 1.0, 0.0);            /* Zdefiniowanie macierzy obrotu wokol osi Y. */
    glColor3f(1.0, 1.0, 0.0);
    glutWireSphere(30, 15, 15);                 /* Zdefiniowanie kwadryki reprezentujacej sfere. */

    // czerwona
    glLoadIdentity();
    glTranslatef(0, 0.0, -200);             /* Translacja obiektu na osi Z. */
    glRotatef(angle2, 0.0, 1.0, 0.0);            /* Zdefiniowanie macierzy obrotu wokol osi Y. */
//    glLoadIdentity();                           /* must have Zaladowanie macierzy jednostkowej. */
    glTranslatef(0.0, 0.0, -70);             /* Translacja obiektu na osi Z. */
 //   glRotatef(angle1 * (-5), 0.0, 1.0, 0.0);            /* Zdefiniowanie macierzy obrotu wokol osi Y. */

    glColor3f(1.0, 0.0, 0.0);
    glutWireSphere(20, 15, 15);                 /* Zdefiniowanie kwadryki reprezentujacej sfere. */

    // zielona
    glLoadIdentity();
    glTranslatef(0, 0.0, -200);             /* Translacja obiektu na osi Z. */
    glRotatef(angle1, 1.0, 0.0, 0.0);            /* Zdefiniowanie macierzy obrotu wokol osi Y. */
    glTranslatef(0.0, 0.0, -60);             /* Translacja obiektu na osi Z. */
//    glRotatef(angle1 * 5, 1.0, 0.0, 0.0);            /* Zdefiniowanie macierzy obrotu wokol osi Y. */
    glColor3f(0.0, 1.0, 0.0);
    glutWireSphere(15, 15, 15);                 /* Zdefiniowanie kwadryki reprezentujacej sfere. */

    angle1 += 0.02f;                             /* Zmiana kata obrotu. */
    angle2 += 0.04f;                             /* Zmiana kata obrotu. */

    // must have below
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
