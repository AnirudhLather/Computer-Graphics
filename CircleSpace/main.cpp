#include <windows.h>
#include <GL/gl.h>
#include <math.h>
#include <GL/glut.h>

void spaceCircle()
{
    for(int i = 1 ; i<4; i++)
    {
        float c = ((rand()+i*i)%6 );
        float c2 = ((rand()+i+i)%7 );
        float c3 = ((rand()+i+10)%2 );
        glColor4f(c,c2,c3 , 1.0);
        glBegin(GL_POLYGON);
            float theta = 0.0;
            int Q = 0;
            for(int i =0 ; i<360 ; i++)
            {
                theta = i*3.14/180;
                glVertex2f(0.230*cos(theta)+0  , 0.255*sin(theta)+0);
            }
        glEnd();
    }
    glFlush();
}

void myKeyboardFunc(unsigned char key,int x,int y)
{
    if(key == ' ')
    {
        spaceCircle();
    }
}

void display()
{
    glColor4f(0.94,0.95,0.25,1);
    glBegin(GL_POLYGON);
        float theta = 0.0;
        int Q = 0;
        for(int i =0 ; i<360 ; i++)
        {
            theta = i*3.14/180;
            glVertex2f(0.230*cos(theta)+0  , 0.255*sin(theta)+0);
        }
    glEnd();
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
    //glutMouseFunc(myMouse);
	glutMainLoop();
}
