/* Przykladowy program demonstrujacy translacje obiektu w OpenGL */
/* z wykorzystaniem biblioteki AUX. */

#include <gl.h>
#include <glaux.h>

float tx = 0.0, ty = 0.0, angle = 0.0;
float sx = 1.0, sy = 1.0;

void CALLBACK my_display() {
    glClear(GL_COLOR_BUFFER_BIT);               /* Wyczyszczenie okna. */
    glLoadIdentity();                           /* Zaladowanie macierzy jednostkowej. */

    glTranslatef(tx, ty, 0);

    glTranslatef(25 , 25 , 0);
    glRotatef(angle, 0, 0, 1);
    glTranslatef(-25 , -25, 0);

    glTranslatef(25, 25, 0);
    glScalef(sx, sy, 1.0);
    glTranslatef(-25, -25, 0);

    if (tx <= 450 && ty <= 0) {
        glColor3f(1.0, 1.0, 1.0);                     /* Ustal kolor obiektu. */
    } else if (tx >= 450 && ty <= 450) {
        glColor3f(1.0, 0.0, 0.0);                     /* Ustal kolor obiektu. */
    } else if (tx >= 0 && ty >= 450) {
        glColor3f(0.0, 1.0, 0.0);                     /* Ustal kolor obiektu. */
    } else if (tx <= 0 && ty >= 0) {
        glColor3f(0.0, 0.0, 1.0);                     /* Ustal kolor obiektu. */
    }

    glBegin(GL_POLYGON);                        /* Zdefiniowanie obiektu. */
    glVertex2i(0, 0);
    glVertex2i(50, 0);
    glVertex2i(50, 50);
    glVertex2i(0, 50);
    glEnd();

    auxSwapBuffers();                           /* Wymiana buforow. */
    if (tx <= 450 && ty <= 0) {
        tx += 0.1f;
        sx += 0.0002f;
        sy += 0.0002f;
    } else if (tx >= 450 && ty <= 450) {
        ty += 0.1f;
        sx -= 0.0002f;
        sy -= 0.0002f;
    } else if (tx >= 0 && ty >= 450) {
        tx -= 0.1f;
        sx += 0.0002f;
        sy += 0.0002f;
    } else if (tx <= 0 && ty >= 0) {
        ty -= 0.1f;
        sx -= 0.0002f;
        sy -= 0.0002f;
    }

    angle += 0.1f;

}

void CALLBACK key_esc() {
    auxQuit();                                  /* Obsluga klawisza ESC. */
    /* Wyjscie z programu po jego nacisnieciu. */
}
void CALLBACK key_left() {
    tx += 100;
}

void CALLBACK keys(unsigned char key, int x, int y) {
    switch(key)
    {
        case AUX_UP:
            ty += 100;
            break;
        case AUX_DOWN:
            ty -= 100;
            break;
        case AUX_RIGHT:
            tx += 100;
            break;
        case AUX_LEFT:
            tx -= 100;
            break;
        case AUX_ESCAPE:
            auxQuit();
        default:
            break;
    }
}

main() {
    auxInitDisplayMode(AUX_DOUBLE | AUX_RGBA);  /* Podwojny bufor koloru, model RGBA. */
    auxInitPosition(0, 0, 500, 500);            /* Rozmiar okna 500x500. */
    auxInitWindow("Open GL");
    auxKeyFunc(AUX_ESCAPE, keys);
    auxIdleFunc(my_display);
    auxMainLoop(my_display);

}

