#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>

#define Round(a) ((int)(a+0.5))
float negative[100];
float negative1[100];
float positive[100];
float positive1[100];

static int i=0;
static int j=0;

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

void checkNegative(float p1,float p2,float p3,float p4,float q1,float q2,float q3,float q4)
{
    if(p1 < 0)
    {
        negative[i] = p1;
        negative1[i] = q1;
        i++;
    }
    if(p1 > 0)
    {
        positive[j] = p1;
        positive1[j] = q1;
        j++;
    }
    if(p2 < 0)
    {
        negative[i] = p2;
        negative1[i] = q2;
        i++;
    }
    if(p2 > 0)
    {
        positive[j] = p2;
        positive1[j] = q2;
        j++;
    }
    if(p3 < 0)
    {
        negative[i] = p3;
        negative1[i] = q3;
        i++;
    }
    if(p3 > 0)
    {
        positive[j] = p3;
        positive1[j] = q3;
        j++;
    }
    if(p4 < 0)
    {
        negative[i] = p4;
        negative1[i] = q4;
        i++;
    }
    if(p4 > 0)
    {
        positive[j] = p4;
        positive1[j] = q4;
        j++;
    }
}

float max1(float p,float q,float r)
{
    if(p > q && p > r)
    {
        return p;
    }
    if(q > p && q > r)
    {
        return q;
    }
    if(r > p && r > q)
    {
        return r;
    }
}

float min1(float p,float q,float r)
{
    if(p < q && p < r)
    {
        return p;
    }
    if(q < p && q < r)
    {
        return q;
    }
    if(r < p && r < q)
    {
        return r;
    }
}

void liangBarskey(float xmin,float xmax,float ymin,float ymax)
{
    float t1;
    float t2;

    float X1;
    float X2;
    float Y1;
    float Y2;

    int a=0;
    int b=0;

    float dx = 1000;
    float dy = -600;

    float p1 = -1 * dx;
    float q1 = -500 - xmin;

    float p2 = 1 * dx;
    float q2 = xmax + 500;

    float p3 = -1 * dy;
    float q3 = 300 - ymin;

    float p4 = 1 * dy;
    float q4 = ymax - 300;

    checkNegative(p1,p2,p3,p4,q1,q2,q3,q4);

    //printf("%d",negative[a]);

    t1 = max1((negative1[a]/negative[a]),(negative1[a+1]/negative[a+1]),0);
    t2 = min1((positive1[b]/positive[b]),(positive1[b+1]/positive[b+1]),1);

    if(t1 > t2)
    {
        printf("Line is discarded");
    }
    else
    {
       X1 = -500 + (t1 * dx);
       Y1 = 300 + (t1 * dy);

       X2 = -500 + (t2 * dx);
       Y2 = 300 + (t2 * dy);

       glBegin(GL_LINES);
       glColor3f(0,0,0);
            glVertex2d(X1,Y1);
            glVertex2d(X2,Y2);
        glEnd();
    }
    glFlush();
}

void window(int a,int b)
{
    glBegin(GL_LINES);
    glColor3f(1,1,1);
        glVertex2d(a-50,b+50);
        glVertex2d(a+50,b+50);

        glVertex2d(a+50,b+50);
        glVertex2d(a+50,b-50);

        glVertex2d(a+50,b-50);
        glVertex2d(a-50,b-50);

        glVertex2d(a-50,b-50);
        glVertex2d(a-50,b+50);
    glEnd();
    glFlush();
    liangBarskey(a-50,a+50,b-50,b+50);
}

void myMouseFunc(int button,int state,int x,int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        window(x-500,300-y);
    }
}

void display()
{
    glColor3f(1,1,1);
        glBegin(GL_LINES);
        glVertex2d(-500,300);
        glVertex2d(500,-300);
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
    glutCreateWindow("Liang Barskey Algorithm");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(myMouseFunc);
    glutMainLoop();
    return 0;
}
