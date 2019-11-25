#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include<math.h>
#define pi 3.142857
void display()
{
    float x, y, i;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,1,0);
	glBegin(GL_POINTS);
        for(i=0;i<(2 * pi);i+=0.001)
        {
            // let 200 is radius of circle and as,
            // circle is defined as x=r*cos(i) and y=r*sin(i)
            x = 700 * cos(i);
            y = 700 * sin(i);
            glVertex2i(x,y);
        }
    glEnd();
	glFlush();
}
int main(int argc,char** argv)
{
	int mode = GLUT_RGB|GLUT_SINGLE;
	glutInit(&argc, argv);
	glutInitDisplayMode(mode);
	glutInitWindowSize(500,500);
	glutCreateWindow("Simple");
	glutDisplayFunc(display);
	//glutKeyboardFunc(key);
	glutMainLoop();
}
