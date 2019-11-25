#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
int x[] = {0,300,60,150,240,12,30,48,252,270,288,80,90,135,165,210,220};
int y[] = {0,0,0,30,0,0,15,0,0,15,0,6,25,25,25,25,6};
int rx[17];
int ry[17];
int rry[17];
int antix[17];
int antiy[17];

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

void printanti()
{
    glColor3d(1,1,1);
    glBegin(GL_LINES);
    glVertex2d( antix[0],antiy[0]);
    glVertex2d(antix[1], antiy[1]);
    glEnd();
    glFlush();
    glColor3d(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2d(antix[2],antiy[2]);
    glVertex2d(antix[3],antiy[3]);
    glVertex2d(antix[4],antiy[4]);
    glEnd();
    glFlush();
    glBegin(GL_POLYGON);
    glVertex2d(antix[5],antiy[5]);
    glVertex2d(antix[6],antiy[6]);
    glVertex2d(antix[7],antiy[7]);
    glEnd();
    glFlush();


    glBegin(GL_POLYGON);
    glVertex2d(antix[8],antiy[8]);
    glVertex2d(antix[9],antiy[9]);
    glVertex2d(antix[10],antiy[10]);
    glEnd();

    glColor3d(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2d(antix[11],antiy[11]);
    glVertex2d(antix[12],antiy[12]);
    glVertex2d(antix[13],antiy[13]);
    glEnd();


    glColor3d(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2d(antix[14],antiy[14]);
    glVertex2d(antix[15],antiy[15]);
    glVertex2d(antix[16],antiy[16]);
    glEnd();

    glFlush();
}

void reflectxaxis()
{

    for(int i = 0 ; i<17 ; i++)
    {
        antiy[i] = antiy[i]*-1;

        //cout<< antix[i]<<"  "<<antiy[i];

    }
    printanti();
}


void translate()
{
    for(int i  = 0 ; i<17 ; i++)
    {

        antix[i] = antix[i]+ 300;
        //cout<< antiy[i]<<endl;
    }
    //printanti();
    reflectxaxis();

}


void reflectyaxis()
{

    for(int i = 0 ; i<17 ; i++)
    {

        //int tx = antix[i];
        //int ty = antiy[i];

        antix[i] = (-1*antix[i]);
//        cout<<"  "<<antix[i]<<endl;
    }
    //printanti();
    translate();
}

void anti60()
{
    for(int i = 0 ; i<17 ; i++)
    {

        int tx = x[i];
        int ty = y[i];

        antix[i] = (tx/2)- (ty*0.866);
        antiy[i] = (0.866 * tx) + (ty/2);


    }
    //printanti();
    reflectyaxis();

}

void rotate90()
{

    for(int i = 0 ; i<17 ; i++)
    {

        rry[i] = -1*y[i];
    }


}

void rotate60()
{
    for(int i  = 0 ; i< 17 ; i++)
    {
        int tx = x[i];
        int ty = rry[i];

        rx[i] = tx/2+ ty * 0.866;
        ry[i] = -1*tx*0.866 + ty/2;
    }
}



void print_L2()
{
    glColor3d(1,1,1);
    glBegin(GL_LINES);
    glVertex2d( rx[0],ry[0]);
    glVertex2d(rx[1], ry[1]);
    glEnd();
    glFlush();


    glColor3d(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2d(rx[2],ry[2]);
    glVertex2d(rx[3],ry[3]);
    glVertex2d(rx[4],ry[4]);
    glEnd();
    glFlush();



    glBegin(GL_POLYGON);
    glVertex2d(rx[5],ry[5]);
    glVertex2d(rx[6],ry[6]);
    glVertex2d(rx[7],ry[7]);
    glEnd();
    glFlush();


    glBegin(GL_POLYGON);
    glVertex2d(rx[8],ry[8]);
    glVertex2d(rx[9],ry[9]);
    glVertex2d(rx[10],ry[10]);
    glEnd();

    glColor3d(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2d(rx[11],ry[11]);
    glVertex2d(rx[12],ry[12]);
    glVertex2d(rx[13],ry[13]);
    glEnd();


    glColor3d(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2d(rx[14],ry[14]);
    glVertex2d(rx[15],ry[15]);
    glVertex2d(rx[16],ry[16]);
    glEnd();

    glFlush();



}

void init()
{
        gluOrtho2D(-500,500,-300,300);

}

void myMouseFunc(int button, int state, int x, int y)
{
    if(/*button == GLUT_BUTTON && state == GLUT_DOWN*/ true)
    {
        //point(x-500,300-y);
        //cout<<"x = "<<x <<"y = "<<y<<endl;
    }
}

void line1_T2()
{

    glBegin(GL_POLYGON);
    glVertex2d(12,0);
    glVertex2d(30,15);
    glVertex2d(48,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(252,0);
    glVertex2d(270,15);
    glVertex2d(288,0);
    glEnd();

    glColor3d(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2d(80,6);
    glVertex2d(90,25);
    glVertex2d(135,25);
    glEnd();


    glColor3d(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2d(165,25);
    glVertex2d(210,25);
    glVertex2d(220,6);
    glEnd();


    glFlush();
    rotate90();
    rotate60();
    print_L2();

}


void line1_T1()
{
    glColor3d(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2d(60,0);
    glVertex2d(150,30);
    glVertex2d(240,0);

    glEnd();
    glFlush();
    //glutPostRedisplay();
    line1_T2();

}


void drawLine()
{
    glColor3d(1,1,1);
    glBegin(GL_LINES);
    glVertex2d(0, 0);
    glVertex2d(300, 0);
    glEnd();
    glFlush();
    //glutPostRedisplay();
}

void drawTriangle()
{
    glColor3d(1,1,1);
    glBegin(GL_LINES);
    glVertex2d( 0,0);
    glVertex2d(300, 0);
    glEnd();
    glFlush();
    line1_T1();
    anti60();

}
void display()
{
    drawTriangle();


    char name[] = "Anirudh Lather";
    char sap[] = "500060209";
    BitmapText(name, -390, 280);
    BitmapText(sap, -370, 260);
    glFlush();
}

int main(int argc,char** argv)
{
    int mode = GLUT_RGB|GLUT_SINGLE;
    glutInit(&argc, argv);
    glutInitWindowPosition(0, 0);
    glutInitDisplayMode(mode);
    glutInitWindowSize(1000,600);
    glutCreateWindow("Fractal Program");
    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
