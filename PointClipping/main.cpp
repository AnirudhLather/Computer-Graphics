#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>

void init()
{
        gluOrtho2D(-500,500,-300,300);
}

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

void pointClipping(int x,int y)
{
    char ab1[] = "Point is inside clipping boundary";
    char ab2[] = "Point is outside clipping boundary";
    if(x > -50 && x < 50 && y > -50 && y < 50)
    {
        char in[] = "Point is inside clipping boundary";
        BitmapText(in, -470, 270);
        glutSwapBuffers();
    }
    else
    {
        char out[] = "Point is outside clipping boundary";
        BitmapText(out, -470, 270);
        glutSwapBuffers();
    }
}

void myMouseFunc(int button,int state,int x,int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        pointClipping(x-500,300-y);
    }
}

void display()
{
	glColor3d(1,1,1);
	glBegin(GL_POLYGON);
		glVertex2f(-50,-50);
		glVertex2f(-50,50);
		glVertex2f(50,50);
		glVertex2f(50,-50);
	glEnd();
    char name[] = "Anirudh Lather";
    char sap[] = "500060209";
    BitmapText(name, 380, 270);
    BitmapText(sap, 400, 250);
    glutSwapBuffers();
    glFlush();
}

int main(int argc,char** argv)
{
    int mode = GLUT_RGB|GLUT_SINGLE;
    glutInit(&argc, argv);
    glutInitWindowPosition(0, 0);
    glutInitDisplayMode(mode);
    glutInitWindowSize(1000,600);
    glutCreateWindow("Point Clipping");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(myMouseFunc);
    glutMainLoop();
    return 0;
}
