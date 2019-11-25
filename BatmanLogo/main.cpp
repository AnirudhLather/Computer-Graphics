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
		glVertex2f(point_x,point_y);
}

void bezierCurve1()
{
    double point_x,point_y,t;
    int x[4] = {-300,-100,-100,0};
    int y[4] = {-100,-100,-100,-250};
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
    int x[4] = {-450,-150,-300,-300};
    int y[4] = {120,50,-50,-100};
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
    int x[4] = {-450,-300,-200,-190};
    int y[4] = {120,120,120,120};
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
    int x[4] = {-190,-150,-100,-70};
    int y[4] = {120,30,50,50};
    for(t=0.0;t<=1.0;t=t+0.001)
    {
        point_x = pow(1-t,3)*x[0] + 3*t*pow(1-t,2)*x[1] + 3*t*t*(1-t)*x[2] + pow(t,3)*x[3];
        point_y = pow(1-t,3)*y[0] + 3*t*pow(1-t,2)*y[1] + 3*t*t*(1-t)*y[2] + pow(t,3)*y[3];
        plotPoints(point_x,point_y);
    }
}

void bezierCurve5()
{
    double point_x,point_y,t;
    int x[4] = {-70,-65,-65,-50};
    int y[4] = {50,110,110,75};
    for(t=0.0;t<=1.0;t=t+0.001)
    {
        point_x = pow(1-t,3)*x[0] + 3*t*pow(1-t,2)*x[1] + 3*t*t*(1-t)*x[2] + pow(t,3)*x[3];
        point_y = pow(1-t,3)*y[0] + 3*t*pow(1-t,2)*y[1] + 3*t*t*(1-t)*y[2] + pow(t,3)*y[3];
        plotPoints(point_x,point_y);
    }
}

void bezierCurve6()
{
    double point_x,point_y,t;
    int x[4] = {-50,-25,-25,0};
    int y[4] = {75,80,80,80};
    for(t=0.0;t<=1.0;t=t+0.001)
    {
        point_x = pow(1-t,3)*x[0] + 3*t*pow(1-t,2)*x[1] + 3*t*t*(1-t)*x[2] + pow(t,3)*x[3];
        point_y = pow(1-t,3)*y[0] + 3*t*pow(1-t,2)*y[1] + 3*t*t*(1-t)*y[2] + pow(t,3)*y[3];
        plotPoints(point_x,point_y);
    }
}

void bezierCurve7()
{
    double point_x,point_y,t;
    int x[4] = {300,100,100,0};
    int y[4] = {-100,-100,-100,-250};
    for(t=0.0;t<=1.0;t=t+0.001)
    {
        point_x = pow(1-t,3)*x[0] + 3*t*pow(1-t,2)*x[1] + 3*t*t*(1-t)*x[2] + pow(t,3)*x[3];
        point_y = pow(1-t,3)*y[0] + 3*t*pow(1-t,2)*y[1] + 3*t*t*(1-t)*y[2] + pow(t,3)*y[3];
        plotPoints(point_x,point_y);
    }
}

void bezierCurve8()
{
    double point_x,point_y,t;
    int x[4] = {450,150,300,300};
    int y[4] = {120,50,-50,-100};
    for(t=0.0;t<=1.0;t=t+0.001)
    {
        point_x = pow(1-t,3)*x[0] + 3*t*pow(1-t,2)*x[1] + 3*t*t*(1-t)*x[2] + pow(t,3)*x[3];
        point_y = pow(1-t,3)*y[0] + 3*t*pow(1-t,2)*y[1] + 3*t*t*(1-t)*y[2] + pow(t,3)*y[3];
        plotPoints(point_x,point_y);
    }
}

void bezierCurve9()
{
    double point_x,point_y,t;
    int x[4] = {450,300,200,190};
    int y[4] = {120,120,120,120};
    for(t=0.0;t<=1.0;t=t+0.001)
    {
        point_x = pow(1-t,3)*x[0] + 3*t*pow(1-t,2)*x[1] + 3*t*t*(1-t)*x[2] + pow(t,3)*x[3];
        point_y = pow(1-t,3)*y[0] + 3*t*pow(1-t,2)*y[1] + 3*t*t*(1-t)*y[2] + pow(t,3)*y[3];
        plotPoints(point_x,point_y);
    }
}

void bezierCurve10()
{
    double point_x,point_y,t;
    int x[4] = {190,150,100,70};
    int y[4] = {120,30,50,50};
    for(t=0.0;t<=1.0;t=t+0.001)
    {
        point_x = pow(1-t,3)*x[0] + 3*t*pow(1-t,2)*x[1] + 3*t*t*(1-t)*x[2] + pow(t,3)*x[3];
        point_y = pow(1-t,3)*y[0] + 3*t*pow(1-t,2)*y[1] + 3*t*t*(1-t)*y[2] + pow(t,3)*y[3];
        plotPoints(point_x,point_y);
    }
}

void bezierCurve11()
{
    double point_x,point_y,t;
    int x[4] = {70,65,65,50};
    int y[4] = {50,110,110,75};
    for(t=0.0;t<=1.0;t=t+0.001)
    {
        point_x = pow(1-t,3)*x[0] + 3*t*pow(1-t,2)*x[1] + 3*t*t*(1-t)*x[2] + pow(t,3)*x[3];
        point_y = pow(1-t,3)*y[0] + 3*t*pow(1-t,2)*y[1] + 3*t*t*(1-t)*y[2] + pow(t,3)*y[3];
        plotPoints(point_x,point_y);
    }
}

void bezierCurve12()
{
    double point_x,point_y,t;
    int x[4] = {50,25,25,0};
    int y[4] = {75,80,80,80};
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
        glBegin(GL_POINTS);
        bezierCurve1();
        bezierCurve2();
        bezierCurve3();
        bezierCurve4();
        bezierCurve5();
        bezierCurve6();
        bezierCurve7();
        bezierCurve8();
        bezierCurve9();
        bezierCurve10();
        bezierCurve11();
        bezierCurve12();
        glEnd();
        glFlush();
    }
}

void display()
{
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
    glutCreateWindow("Batman Logo");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(myMouseFunc);
    //glutKeyboardFunc(myKeyboardFunc);
    glutMainLoop();
    return 0;
}
