#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor4f(1,1,0,1);
	glBegin(GL_POLYGON);
		glVertex2f(0,0.5);
		glVertex2f(-0.5,0);
		glVertex2f(0.5,0);
		//glVertex2f(0.5,-0.5);
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
