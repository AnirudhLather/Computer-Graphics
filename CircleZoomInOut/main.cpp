#include <windows.h>
#include <GL/gl.h>
#include <math.h>
#include <GL/glut.h>

void displayCircle()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor4f(1,1,1,1);
    glBegin(GL_POLYGON);
        float theta = 0.0;
        int Q = 0;
        for(int i =0 ; i<360 ; i++)
        {
            theta = i*3.14/180;
            glVertex2f(0.350*cos(theta)+0  , 0.375*sin(theta)+0);
        }
    glEnd();
    glFlush();
}

void myMouse(int button,int state,int x,int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        displayCircle();
    }
}

void myKeyboard(unsigned char key,int x,int y)
{
    if(key == ' ')
    {
        displayCircle();
        //display();
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor4f(1,1,1,1);
    glBegin(GL_POLYGON);
        float theta = 0.0;
        int Q = 0;
        for(int i =0 ; i<360 ; i++)
        {
            theta = i*3.14/180;
            glVertex2f(0.230*cos(theta)+0  , 0.255*sin(theta)+0);
        }
    glEnd();
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
	glutKeyboardFunc(myKeyboard);
    glutMouseFunc(myMouse);
	glutMainLoop();
}
