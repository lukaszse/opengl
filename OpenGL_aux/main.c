#include <DevGL\gl.h>
#include <DevGL\glu.h>
#include <DevGL\glut.h>
#include <DevGL\glaux.h>

float tx = 0.0, ty = 0.0;


void CALLBACK my_display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    glTranslatef(tx, ty, 0);
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(20,20);
    glVertex2f(20,100);
    glVertex2f(100,100);
    glVertex2f(100,20);
    glEnd();

    auxSwapBuffers();
}

void CALLBACK key_esc(void)
{
    auxQuit();
}

void CALLBACK goLeft(void ) {
    tx -= 10;
}

void CALLBACK goRight(void ) {
    tx += 10;
}

void CALLBACK goUp(void) {
    ty -= 10;
}

void CALLBACK goDown(void) {
    ty += 10;
}


int main(int argc, char **argv)
{
    auxInitDisplayMode(AUX_DOUBLE | AUX_RGBA);
    auxInitPosition(0, 0, 500, 500);
    auxInitWindow("OpenGL + AUX");
    auxKeyFunc(AUX_ESCAPE, key_esc);
    auxKeyFunc(AUX_LEFT, goLeft);
    auxKeyFunc(AUX_RIGHT, goRight);
    auxKeyFunc(AUX_DOWN, goUp);
    auxKeyFunc(AUX_UP, goDown);
    auxIdleFunc(my_display);
    auxMainLoop(my_display);
}

