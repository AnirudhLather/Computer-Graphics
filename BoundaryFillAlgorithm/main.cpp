#include <math.h>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>

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

struct Point
{
	int x;
	int y;
};

struct Color
{
	float r;
	float g;
	float b;
};

void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
}

Color getPixelColor(int x, int y)
{
	Color color;
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);
	return color;
}

void setPixelColor(int x, int y, Color color)
{
	glColor3f(color.r, color.g, color.b);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

void boundaryFillAlgorithm(int x, int y, Color fillColor, Color boundaryColor)
{
	Color color;
	color = getPixelColor(x, y);

	if(color.r != boundaryColor.r && color.g != boundaryColor.g && color.b != boundaryColor.b && color.r != fillColor.r && color.g != fillColor.g && color.b != fillColor.b)
	{
		setPixelColor(x, y, fillColor);
		boundaryFillAlgorithm(x+1, y, fillColor, boundaryColor);
		boundaryFillAlgorithm(x, y+1, fillColor, boundaryColor);
		boundaryFillAlgorithm(x-1, y, fillColor, boundaryColor);
		boundaryFillAlgorithm(x, y-1, fillColor, boundaryColor);
	}
	return;
}

void onMouseClick(int button, int state, int x, int y)
{
	Color fillColor = {0.0f, 2.0f, 0.0f};
	Color boundaryColor = {0.0f, 0.0f, 0.0f};

	boundaryFillAlgorithm(x,480-y, fillColor, boundaryColor);
}

void circle(Point pC, float radius)
{
	float step = 1/radius;
	float x, y;

	for(float theta = 0; theta <= 360; theta += step)
	{
		x = pC.x + (radius * cos(theta));
		y = pC.y + (radius * sin(theta));
		glVertex2i(x, y);
	}
}

void display(void)
{
	Point pt = {320, 240};
	float radius = 50;

	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
		circle(pt, radius);
	glEnd();
	char name[] = "Anirudh Lather";
    char sap[] = "500060209";
    BitmapText(name, 500, 450);
    BitmapText(sap, 520, 430);
    glutSwapBuffers();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Boundary Fill Algorithm");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(onMouseClick);
	glutMainLoop();
	return 0;
}
