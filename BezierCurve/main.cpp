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

void plotPoints(float point_x,float point_y)
{
    glColor3f(1,1,1);
    glBegin(GL_POINTS);
		glVertex2f(point_x,point_y);
	glEnd();
	glFlush();
}

void bezierCurve1()
{
    double point_x,point_y,t;
    int x[4] = {200,300,20,0};
    int y[4] = {0,400,20,200};
    for(t=0.0;t<=1.0;t=t+0.001)
    {
        point_x = pow(1-t,3)*x[0] + 3*t*pow(1-t,2)*x[1] + 3*t*t*(1-t)*x[2] + pow(t,3)*x[3];
        point_y = pow(1-t,3)*y[0] + 3*t*pow(1-t,2)*y[1] + 3*t*t*(1-t)*y[2] + pow(t,3)*y[3];
        plotPoints(point_x,point_y);
    }
}

void bezierCurve2()
{
    double point_x,point_y,t;
    int x[4] = {-200,-300,-300,0};
    int y[4] = {0,400,300,200};
    for(t=0.0;t<=1.0;t=t+0.001)
    {
        point_x = pow(1-t,3)*x[0] + 3*t*pow(1-t,2)*x[1] + 3*t*t*(1-t)*x[2] + pow(t,3)*x[3];
        point_y = pow(1-t,3)*y[0] + 3*t*pow(1-t,2)*y[1] + 3*t*t*(1-t)*y[2] + pow(t,3)*y[3];
        plotPoints(point_x,point_y);
    }
}

void bezierCurve3()
{
    double point_x,point_y,t;
    int x[4] = {-200,-300,-300,0};
    int y[4] = {0,-400,-300,-200};
    for(t=0.0;t<=1.0;t=t+0.001)
    {
        point_x = pow(1-t,3)*x[0] + 3*t*pow(1-t,2)*x[1] + 3*t*t*(1-t)*x[2] + pow(t,3)*x[3];
        point_y = pow(1-t,3)*y[0] + 3*t*pow(1-t,2)*y[1] + 3*t*t*(1-t)*y[2] + pow(t,3)*y[3];
        plotPoints(point_x,point_y);
    }
}

void bezierCurve4()
{
    double point_x,point_y,t;
    int x[4] = {200,300,300,0};
    int y[4] = {0,-400,-300,-200};
    for(t=0.0;t<=1.0;t=t+0.001)
    {
        point_x = pow(1-t,3)*x[0] + 3*t*pow(1-t,2)*x[1] + 3*t*t*(1-t)*x[2] + pow(t,3)*x[3];
        point_y = pow(1-t,3)*y[0] + 3*t*pow(1-t,2)*y[1] + 3*t*t*(1-t)*y[2] + pow(t,3)*y[3];
        plotPoints(point_x,point_y);
    }
}

void myMouseFunc(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        bezierCurve1();
        bezierCurve2();
        bezierCurve3();
        bezierCurve4();
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    glBegin(GL_LINES);
		glVertex2f(-500,0);
		glVertex2f(500,0);
		glVertex2f(0,300);
		glVertex2f(0,-300);
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
    glutCreateWindow("Bezier Curve Implementation");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(myMouseFunc);
    //glutKeyboardFunc(myKeyboardFunc);
    glutMainLoop();
    return 0;
}
