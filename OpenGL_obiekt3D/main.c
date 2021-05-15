#include <DevGL\gl.h>
#include <DevGL\glu.h>
#include <DevGL\glut.h>

int main() {
    return 0;
}


void specialKey(unsigned char key, int x, int y){
    switch (key) {
        case '1':
            break;
        case '2':
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