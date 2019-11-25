#include <gl/glut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#define RAND_MAX = 9

void BitmapText(char* string, float xc, float yc)
{
    char c;
    int i = 0;
    glRasterPos2f(xc, yc);

    for (i = 0; string[i] != '\0'; i++)
    {
        c = string[i];
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, c);
    }
}

void BitmapCordinates(int x , int y, float xc, float yc)
{
    int i = 0;
    glRasterPos2f(xc, yc);

    char array[1000];
    sprintf( array, "x = %d , y = %d", x ,y);
    for (i = 0; array[i] != '\0'; i++)
    {
        char c = array[i];
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, c);
    }
}

struct Point
{
	GLint x;
	GLint y;
};

Point p1, p2;

void square(float x , float y)
{
	glClear(GL_COLOR_BUFFER_BIT);
    glColor4f(0.0,0.0,0.0,1);
    int a =80;
    for(int i = 1 ; i<4; i++)
    {
        float c = ((rand()+i*i)%6 );
        float c2 = ((rand()+i+i)%7 );
        float c3 = ((rand()+i+10)%2 );
        glColor4f(c,c2,c3 , 1.0);
        glBegin(GL_POLYGON);
        glVertex2d(x-a, y+a);
        glVertex2d(x+a , y+a);
        glVertex2d(x+a , y-a);
        glVertex2d(x-a , y-a);
        glEnd();
        a=a-20;
    }
	glFlush();
}

void myMouseFunc(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
		float a = x ;
		float b = 480-y;
		square(a,b);
	}
}

void init()
{
	//glClearColor(0.0, 0.0, 0.0, 1.0);
	//glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(1.0f);
	gluOrtho2D(0.0f, 640.0f, 0.0f, 480.0f);
}

void display(void)
{
    glColor3d(1,1,1);
    char name[] = "Anirudh Lather";
    char sap[] = "500060209";
    BitmapText(name, -0.5, 0.5);
    BitmapText(sap, -0.5, 0.5);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Mouse Function");
	glutDisplayFunc(display);
	glutMouseFunc(myMouseFunc);
	init();
	glutMainLoop();
	return 0;
}
