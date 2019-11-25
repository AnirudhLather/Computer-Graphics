#include <windows.h>
#include <GL/gl.h>
#include <math.h>
#include <GL/glut.h>
#include<stdio.h>

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

void myKeyboardFunc(unsigned char Key, int x, int y)
{
    switch(Key)
    {
        case 27:
            glutDestroyWindow(glutGetWindow());
            break;
    }
    glutPostRedisplay();
}

void hut()
{
    glClear(GL_COLOR_BUFFER_BIT);
    //Ground
    glColor4f(0.33,0.41,0.0,1);
    glBegin(GL_POLYGON);
        glVertex2f(-1.0,-0.5);
        glVertex2f(1.0,-0.5);
        glVertex2f(1.0,-1.0);
        glVertex2f(-1.0,-1.0);
    glEnd();

    //Sky
    glColor4f(0,0,0,1);
    glBegin(GL_POLYGON);
        glVertex2f(-1.0,-0.5);
        glVertex2f(1.0,-0.5);
        glVertex2f(1.0,1.0);
        glVertex2f(-1.0,1.0);
    glEnd();

    //Sun
    glColor4f(1,1,1,1);
    glBegin(GL_POLYGON);
        float theta = 0.0;
        int Q = 0;
        for(int i =0 ; i<360 ; i++)
        {
            theta = i*3.14/180;
            glVertex2f(0.230*cos(theta)+0.50  , 0.255*sin(theta)+0.69);
        }
    glEnd();

    //Front Wall
	glColor4f(0.7,0.2,0.3,1);
	glBegin(GL_POLYGON);
		glVertex2f(-0.7,-0.7);
		glVertex2f(-0.7,0);
		glVertex2f(-0.2,0);
		glVertex2f(-0.2,-0.7);
    glEnd();

    //Side Wall
    glColor4f(0.1,0.5,0.3,1);
	glBegin(GL_POLYGON);
		glVertex2f(-0.2,-0.7);
		glVertex2f(-0.2,0);
		glVertex2f(0.7,0);
		glVertex2f(0.7,-0.7);
	glEnd();

	//Upper Roof
	glColor4f(0.1,0.5,0,1);
	glBegin(GL_TRIANGLES);
        glVertex2f(-0.7,0);
        glVertex2f(-0.45,0.5);
		glVertex2f(-0.2,0);
	glEnd();

	//Upper Side Roof
	glColor4f(0.7,0.3,0.9,1);
	glBegin(GL_POLYGON);
        glVertex2f(-0.2,0);
        glVertex2f(-0.45,0.5);
        glVertex2f(0.5,0.5);
        glVertex2f(0.7,0);
    glEnd();

    //Door
    glColor4f(0.1,0.9,0.5,1);
    glBegin(GL_POLYGON);
        glVertex2f(-0.6,-0.7);
        glVertex2f(-0.6,-0.3);
        glVertex2f(-0.3,-0.3);
        glVertex2f(-0.3,-0.7);
    glEnd();

    //Window
    glColor4f(0.3,0.9,0.9,1);
    glBegin(GL_POLYGON);
        glVertex2f(0,-0.5);
        glVertex2f(0,-0.2);
        glVertex2f(0.5,-0.2);
        glVertex2f(0.5,-0.5);
    glEnd();
	glFlush();
}

void myMouse(int button,int state,int x,int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        hut();
    }
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
    //Ground
    glColor4f(0.14,0.74,0.14,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(-1.0,-0.5);
        glVertex2f(1.0,-0.5);
        glVertex2f(1.0,-1.0);
        glVertex2f(-1.0,-1.0);
    glEnd();

    //Sky
    glColor4f(0.56,0.65,1.0,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(-1.0,-0.5);
        glVertex2f(1.0,-0.5);
        glVertex2f(1.0,1.0);
        glVertex2f(-1.0,1.0);
    glEnd();

    //Sun
    glColor4f(0.94,0.95,0.25,1);
    glBegin(GL_POLYGON);
        float theta = 0.0;
        int Q = 0;
        for(int i =0 ; i<360 ; i++)
        {
            theta = i*3.14/180;
            glVertex2f(0.230*cos(theta)+0.50  , 0.255*sin(theta)+0.69);
        }
    glEnd();

    //Front Wall
	glColor4f(0.7,0.2,0.3,1);
	glBegin(GL_POLYGON);
		glVertex2f(-0.7,-0.7);
		glVertex2f(-0.7,0);
		glVertex2f(-0.2,0);
		glVertex2f(-0.2,-0.7);
    glEnd();

    //Side Wall
    glColor4f(0.1,0.5,0.3,1);
	glBegin(GL_POLYGON);
		glVertex2f(-0.2,-0.7);
		glVertex2f(-0.2,0);
		glVertex2f(0.7,0);
		glVertex2f(0.7,-0.7);
	glEnd();

	//Upper Roof
	glColor4f(0.1,0.5,0,1);
	glBegin(GL_TRIANGLES);
        glVertex2f(-0.7,0);
        glVertex2f(-0.45,0.5);
		glVertex2f(-0.2,0);
	glEnd();

	//Upper Side Roof
	glColor4f(0.7,0.3,0.9,1);
	glBegin(GL_POLYGON);
        glVertex2f(-0.2,0);
        glVertex2f(-0.45,0.5);
        glVertex2f(0.5,0.5);
        glVertex2f(0.7,0);
    glEnd();

    //Door
    glColor4f(0.1,0.9,0.5,1);
    glBegin(GL_POLYGON);
        glVertex2f(-0.6,-0.7);
        glVertex2f(-0.6,-0.3);
        glVertex2f(-0.3,-0.3);
        glVertex2f(-0.3,-0.7);
    glEnd();

    //Window
    glColor4f(0.3,0.9,0.9,1);
    glBegin(GL_POLYGON);
        glVertex2f(0,-0.5);
        glVertex2f(0,-0.2);
        glVertex2f(0.5,-0.2);
        glVertex2f(0.5,-0.5);
    glEnd();
    glColor3d(0,0,0);
    char name[] = "Anirudh Lather";
    char sap[] = "500060209";
    BitmapText(name, -0.9,0.9);
    BitmapText(sap, -0.85,0.8);
    glutSwapBuffers();
	glFlush();
}
int main(int argc,char** argv)
{
	int mode = GLUT_RGB|GLUT_SINGLE;
	glutInit(&argc, argv);
	glutInitDisplayMode(mode);
	glutInitWindowSize(720,600);
	glutCreateWindow("Simple");
	glutDisplayFunc(display);
	glutKeyboardFunc(myKeyboardFunc);
    glutMouseFunc(myMouse);
	glutMainLoop();
}
