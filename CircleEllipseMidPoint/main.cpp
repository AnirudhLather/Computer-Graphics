#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>

#define Round(a) ((int)(a+0.5))

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

void setPixel(int x,int y)
{
    glBegin(GL_POINTS);
        glColor3d(1,1,1);
        glVertex2f(Round(x),Round(y));
    glEnd();
    glFlush();
}

void ellipsePoints(int xC,int yC,int x,int y)
{
    setPixel(xC + x,yC + y);
    setPixel(xC - x,yC + y);
    setPixel(xC + x,yC - y);
    setPixel(xC - x,yC - y);
}

void ellipse(int xC,int yC,int a,int b)
{
    int a2 = a*a;
    int b2 = b*b;
    int twoa2 = 2 * a2;
    int twob2 = 2 * b2;

    int p0;
    int x = 0;
    int y = b;
    int dx = 0;
    int dy = twoa2 * y;

    ellipsePoints(xC,yC,x,y);

    //For Region-1
    p0 = Round(b2 - (a2 * b) + 0.25 * a2);
    while(dx < dy)
    {
        if(p0 <0)
        {
            x = x + 1;
            dx = dx + twob2;
            p0 = p0 + b2 + dx;
        }
        else
        {
            x = x + 1;
            dx = dx + twob2;
            y = y - 1;
            dy = dy - twoa2;
            p0 = p0 + b2 + dx - dy;
        }
        ellipsePoints(xC,yC,x,y);
    }

    //For Region-2
    p0 = Round(b2*(x+0.5)*(x+0.5) + a2*(y-1)*(y-1) - a2*b2);
    while(y>0)
    {
        if(p0>0)
        {
            y = y - 1;
            dy = dy - twoa2;
            p0 = p0 + a2 - dy;
        }
        else
        {
            y = y - 1;
            dy = dy - twoa2;
            x = x + 1;
            dx = dx + twob2;
            p0 = p0 + a2 - dy + dx;
        }
        ellipsePoints(xC,yC,x,y);
    }
}

void circlePoints(int xC,int yC,int x,int y)
{
    setPixel(xC + x,yC + y);
    setPixel(xC - x,yC + y);
    setPixel(xC + x,yC - y);
    setPixel(xC - x,yC - y);
    setPixel(xC + y,yC + x);
    setPixel(xC - y,yC + x);
    setPixel(xC + y,yC - x);
    setPixel(xC - y,yC - x);
}

void circle(int xC,int yC,int r)
{
    int x = 0;
    int y = r;
    int p0 = 1-r;
    circlePoints(xC,yC,x,y);
    while(x<y)
    {
        if(p0<0)
        {
            p0 = p0 + 2 * x + 1;
            x = x + 1;
        }
        else
        {
            p0 = p0 + 2 * (x - y) + 1;
            x = x + 1;
            y = y - 1;
        }
        circlePoints(xC,yC,x,y);
    }
}

void myMouseFunc(int button,int state,int x,int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if((300-y)>0)
        {
            char S1[100];
            char S2[100];
            sprintf(S1,"Major Axis : 100");
            BitmapText(S1,x-560,370-y);
            sprintf(S2,"Minor Axis : 50");
            BitmapText(S2,x-560,350-y);
            ellipse((x-500),(300-y),100,50);
        }
        if((300-y)<0)
        {
            char S3[100];
            sprintf(S3,"Radius : 50");
            BitmapText(S3,x-540,370-y);
            circle((x-500),(300-y),50);
        }
    }
}

void display()
{
    glColor3d(1,1,1);
        glBegin(GL_LINES);
        glVertex2d(-500,0);
        glVertex2d(500,0);
        glVertex2d(0,-300);
        glVertex2d(0,300);
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
    glutCreateWindow("Circle using Mid point Theorem");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(myMouseFunc);
    glutMainLoop();
    return 0;
}
