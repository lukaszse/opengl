/* Przykladowy program demonstrujacy skalowanie obiektu w OpenGL */
/* z wykorzystaniem biblioteki AUX. */
/* Skalowanie odbywa sie wzgledem srodka obiektu. */

#include <gl.h>
#include <glu.h>
#include <glut.h>
#include <glaux.h>

float sx = 1.0, sy = 1.0, angle = 0, mov = 0;
int flag  = 0;

void CALLBACK my_display() {
    glClear(GL_COLOR_BUFFER_BIT);               /* Wyczyszczenie okna. */
    glLoadIdentity();                           /* Zaladowanie macierzy jednostkowej. */


    glTranslatef(mov, 0, 0);

    /* Skladanie  (w odwrotnej kolejnosci). */
    glTranslatef(250, 250, 0);                  /* 3. Przesumacierzyniecie obiektu do pozycji wejsciowej. */
    glScalef(sx, sy, 1.0);                      /* 2. Zdefiniowanie macierzy skalowania wzgledem osi X i Y. */
    glTranslatef(-250, -250, 0);                /* 1. Przesuniecie srodka obiektu tak, aby pokrywal sie ze */
    /*    srodkiem ukladu wspolrzednych. */

    glTranslatef(250, 250, 0);
    glRotatef(angle, 0, 0, 1);
    glTranslatef(-250, -250, 0);                /* 1. Przesuniecie srodka obiektu tak, aby pokrywal sie ze */


    glColor3f(0.3, 0.5, 0.8);                     /* Ustal kolor obiektu. */
    glBegin(GL_POLYGON);                        /* Zdefiniowanie obiektu. */
    glVertex2i(200, 200);                        /* Kwadrat o boku 100 i srodku w punkcie (250,250). */
    glVertex2i(300, 200);
    glVertex2i(300, 300);
    glVertex2i(200, 300);

    glEnd();

    auxSwapBuffers();                           /* Wymiana buforow. */



    if(flag == 1) {
        sx -= 0.0002;                               /* Ustalenie predkosci skalowania. */
        sy -= 0.0002;                               /* Wartosci mozna zmieniac eksperymentalnie. */
        angle += 0.02;
        mov += 0.03;

    } else {
        sx += 0.0002;                               /* Ustalenie predkosci skalowania. */
        sy += 0.0002;                               /* Wartosci mozna zmieniac eksperymentalnie. */
        angle -= 0.02;
        mov -= 0.03;
    }

    if(sx >= 2) {
        flag = 1;
    } else if(sx <= 1) {
        flag = 0;
    }
}

void CALLBACK key_esc() {
    auxQuit();                                  /* Obsluga klawisza ESC. */
    /* Wyjscie z programu po jego nacisnieciu. */
}


int main() {
    auxInitDisplayMode(AUX_DOUBLE | AUX_RGBA);  /* Podwojny bufor koloru, model RGBA. */
    auxInitPosition(0, 0, 500, 500);            /* Rozmiar okna 500x500. */
    auxInitWindow("Open GL");
    auxKeyFunc(AUX_ESCAPE, key_esc);
    auxIdleFunc(my_display);
    auxMainLoop(my_display);

    return 0;
}
