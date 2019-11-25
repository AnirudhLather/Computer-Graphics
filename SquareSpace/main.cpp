#include <gl/glut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#define RAND_MAX = 9

struct Point
{
	GLint x;
	GLint y;
};

Point p1, p2;

void square(float x,float y)
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
        glVertex2d(x-a+300, y+a+240);
        glVertex2d(x+a+300 , y+a+240);
        glVertex2d(x+a+300 , y-a+240);
        glVertex2d(x-a+300 , y-a+240);
        glEnd();
        a=a-20;
    }
	glFlush();
}

void myKeyboardFunc(unsigned char key,int x,int y)
{
	if(key == ' ')
    {
		square(0.5,0.5);
	}
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(1.0f);
	gluOrtho2D(0.0f, 640.0f, 0.0f, 480.0f);
}

void display(void)
{

}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Keyboard Function");
	glutDisplayFunc(display);
	//glutMouseFunc(myMouseFunc);
	glutKeyboardFunc(myKeyboardFunc);
	init();
	glutMainLoop();
	return 0;
}
