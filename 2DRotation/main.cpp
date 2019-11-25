#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>
#include<math.h>

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

void rotationClock()
{
    float a[3][4],b[3][4],t[3][3];

    //Square Matrix
    b[0][0] = 100;
    b[0][1] = 200;
    b[0][2] = 200;
    b[0][3] = 100;
    b[1][0] = 200;
    b[1][1] = 200;
    b[1][2] = 100;
    b[1][3] = 100;
    b[2][0] = 1;
    b[2][1] = 1;
    b[2][2] = 1;
    b[2][3] = 1;

    //Transformation Matrix
    t[0][0] = cos(30);
    t[0][1] = sin(30);
    t[0][2] = 0;
    t[1][0] = -sin(30);
    t[1][1] = cos(30);
    t[1][2] = 0;
    t[2][0] = 0;
    t[2][1] = 0;
    t[2][2] = 1;

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            a[i][j] = 0;
            for(int k=0;k<3;k++)
            {
                a[i][j] += t[i][k] * b[k][j];
            }
        }
    }
    char clockwis[] = "Clock-Wise Rotation by 30 Degree";
    BitmapText(clockwis, -470, 280);
    glutSwapBuffers();
    glColor3f(1,1,0.7);
    glBegin(GL_POLYGON);
		glVertex2f(a[0][0],a[1][0]);
		glVertex2f(a[0][1],a[1][1]);
		glVertex2f(a[0][2],a[1][2]);
		glVertex2f(a[0][3],a[1][3]);
	glEnd();
	glFlush();
}

void rotationAnticlock()
{
    float a[3][4],b[3][4],t[3][3];

    //Square Matrix
    b[0][0] = 100;
    b[0][1] = 200;
    b[0][2] = 200;
    b[0][3] = 100;
    b[1][0] = 200;
    b[1][1] = 200;
    b[1][2] = 100;
    b[1][3] = 100;
    b[2][0] = 1;
    b[2][1] = 1;
    b[2][2] = 1;
    b[2][3] = 1;

    //Transformation Matrix
    t[0][0] = cos(30);
    t[0][1] = -sin(30);
    t[0][2] = 0;
    t[1][0] = sin(30);
    t[1][1] = cos(30);
    t[1][2] = 0;
    t[2][0] = 0;
    t[2][1] = 0;
    t[2][2] = 1;

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            a[i][j] = 0;
            for(int k=0;k<3;k++)
            {
                a[i][j] += t[i][k] * b[k][j];
            }
        }
    }
    char anti[] = "Anti Clock-Wise Rotation by 30 Degree";
    BitmapText(anti, -470, 280);
    glutSwapBuffers();
    glColor3f(1,1,0.7);
    glBegin(GL_POLYGON);
		glVertex2f(a[0][0],a[1][0]);
		glVertex2f(a[0][1],a[1][1]);
		glVertex2f(a[0][2],a[1][2]);
		glVertex2f(a[0][3],a[1][3]);
	glEnd();
	glFlush();
}

void myMouseFunc(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        rotationClock();
    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        rotationAnticlock();
    }
}

void display()
{
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
		glVertex2f(100,200);
		glVertex2f(200,200);
		glVertex2f(200,100);
		glVertex2f(100,100);
	glEnd();
    char name[] = "Anirudh Lather";
    char sap[] = "500060209";
    BitmapText(name, 350, 280);
    BitmapText(sap, 370, 260);
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
    glutCreateWindow("2-D Rotation");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(myMouseFunc);
    glutMainLoop();
    return 0;
}
