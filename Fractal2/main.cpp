#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <time.h>

int points=200000;
int number=1;

void color()
{
    switch (number%9+1)
    {
        case 1:
            glColor3f(1.0,0.0,0.0);
            break;
        case 2:
            glColor3f(0.0,1.0,0.0);
            break;
        case 3:
            glColor3f(0.0,0.0,1.0);
            break;
        case 4:
            glColor3f(1.0,1.0,0.0);
            break;
        case 5:
            glColor3f(1.0,0.0,1.0);
            break;
        case 6:
            glColor3f(0.0,1.0,1.0);
            break;
        case 7:
            glColor3f(1.0,0.5,1.0);
            break;
        case 8:
            glColor3f(0.5,1.0,0.5);
            break;
        default:
            glColor3f(0,0,0);
            break;
    }
    number++;
}

void init(void)
{
      glClearColor(1.0, 1.0, 1.0, 1.0);
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluOrtho2D(-500.0, 500.0, -300.0, 300.0);
      glMatrixMode(GL_MODELVIEW);
}

void pentagon(void)
{
    typedef GLfloat point2[2];
    point2 vertices[5]={{100,0},{400,0},{495,300},{250,480},{5,300}};
    int j, k;
    int rand();
    point2 p ={0.0,50.0};

    glClear(GL_COLOR_BUFFER_BIT);

    for( k=0; k<points; k++)
    {
         j=rand()%5;
         p[0] = (p[0]+vertices[j][0])*(3.0/8.0);
         p[1] = (p[1]+vertices[j][1])*(3.0/8.0);
          glBegin(GL_POINTS);
               glVertex2fv(p);
          glEnd();
     }
     glFlush();
     glutSwapBuffers();
}

void mouseFunc(int button,int state,int x,int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        points=10000;
        color();
    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        points=200000;
        color();
    }
}

void display()
{
    pentagon();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Fractals");
    glutDisplayFunc(display);
    glutMouseFunc(mouseFunc);
    init();
    glutMainLoop();
    return 0;
}
