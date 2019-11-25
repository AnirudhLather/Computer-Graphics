#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>
#include<math.h>

int ww=400, wh=400;
int count = 0, x1 = 0, ya1 = 0, x2 = 0, ya2 = 0, r = 0;
int wx1 = 0, wy1 = 0, wx2 = 100, wy2 = 100;

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

void init(void)
{
 	glClearColor(0.0,0.0,0.0,0.0);
 	glMatrixMode(GL_PROJECTION);
 	gluOrtho2D(-500,500,-300,300);
}
int calculateX(int y)
{
	return (((ya1-y)*(x2-x1))/((ya2-ya1)*1.0))+x1;
}
int calculateY(int x)
{
  	return ya1-(((x1-x)*(ya2-ya1))/((x2-x1)*1.0));
}
void clipline(int temp1 ,int temp2)
{
    if(temp1 == 0 || temp2 == 0)
	{
		int x,y,temp = temp1;
        if(temp1 == 0)
        	temp = temp2;
      	if(temp == 8)
		{
        	y = wy2;
        	x = calculateX(y);
      	}
      	else if(temp == 2)
		{
        	x = wx2;
        	y = calculateY(x);
      	}
      	else if(temp == 4)
		{
        	y = wy1;
        	x = calculateX(y);
      	}
      	else if(temp == 1)
		{
        	x = wx1;
        	y = calculateY(x);
      	}
      	else if(temp == 9)
		{
        	x = wx1;
        	y = calculateY(x);
        	if(y>wy2)
			{
        		y = wy2;
          		x = calculateX(y);
        	}
      	}
      	else if(temp == 10)
		{
        	x = wx2;
        	y = calculateY(x);
        	if(y>wy2)
			{
         		y = wy2;
          		x = calculateX(y);
        	}
      	}
      	else if(temp == 5)
		{
        	x = wx1;
        	y = calculateY(x);
        	if(y<wy1)
			{
          		y = wy1;
          		x = calculateX(y);
        	}
        }
      	else
		{
        	x = wx2;
        	y = calculateY(x);
        	if(y<wy1)
			{
          		y = wy1;
          		x = calculateX(y);
        	}
      	}
		if(temp1 == 0)
		{
        	x2 = x;
        	ya2 = y;
      	}
        else
		{
        	x1 = x;
        	ya1 = y;
      	}
    }
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINES);
    	glVertex2i(x1,ya1);
    	glVertex2i(x2,ya2);
    glEnd();
}
void cohenSutherland()
{
  	int temp1 = 0;
  	if(x1<wx1)
        temp1+= 1;
  	if(x1>wx2)
      	temp1+= 2;
  	if(ya1<wy1)
      	temp1+= 4;
  	if(ya1>wy2)
      	temp1+= 8;
  	int temp2 = 0;
  	if(x2<wx1)
      	temp2+= 1;
  	if(x2>wx2)
      	temp2+= 2;
  	if(ya2<wy1)
      	temp2+= 4;
  	if(ya2>wy2)
      	temp2+= 8;

  	if((temp1|temp2) == 0)
	{
        glColor3f(1,1,1);
    	char visi1[] = "Fully Visible";
        BitmapText(visi1, -450, 280);
    	glColor3f(0.0,0.0,0.0);
    		glBegin(GL_LINES);
    		glVertex2i(x1,ya1);
    		glVertex2i(x2,ya2);
    	glEnd();
  	}
  	else if((temp1&temp2) == 1||(temp1&temp2) == 2||(temp1&temp2) == 4||(temp1&temp2) == 8)
    {
        glColor3f(1,1,1);
    	char visi2[] = "Invisible";
        BitmapText(visi2, -450, 280);
    }
  	else
	{
        glColor3f(1,1,1);
    	char visi3[] = "Partially Visible";
        BitmapText(visi3, -450, 280);
    	clipline(temp1,temp2);
  	}
}
void plotPoint(int x,int y)
{
 	glPointSize(2);
 	glBegin(GL_POINTS);
  		glVertex2i(x,y);
 	glEnd();
}
void mouseFunc(int button,int action,int xMouse,int yMouse)
{
 	if(button == GLUT_LEFT_BUTTON && action == GLUT_DOWN)
 	{
  		if(!count)
  		{
   			x1 = xMouse - 500;
   			ya1 = 300 - yMouse;
   			count = 1;
  		}
  		else
  		{
    		x2 = xMouse - 500;
    		ya2 = 300 - yMouse;
    		glColor3f(0.5,1,1);
    		glBegin(GL_LINES);
    			glVertex2i(x1,ya1);
    			glVertex2i(x2,ya2);
    		glEnd();
    		cohenSutherland();
    		count=0;
  		}
 	}
 	glFlush();
}

void display(void)
{
  	glColor3f(1,1,1);
  	glBegin(GL_POLYGON);
  		glVertex2f(wx1,wy1);
  		glVertex2f(wx1,wy2);
  		glVertex2f(wx2,wy2);
  		glVertex2f(wx2,wy1);
  	glEnd();
  	char name[] = "Anirudh Lather";
    char sap[] = "500060209";
    BitmapText(name, 350, 280);
    BitmapText(sap, 370, 260);
    glutSwapBuffers();
    glFlush();
}

int main(int argc, char** argv)
{
 	glutInit(&argc,argv);
 	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 	glutInitWindowPosition(0,0);
 	glutInitWindowSize(1000,600);
 	glutCreateWindow("Cohen Sutherland Line Clipping Algorithm");

 	init();
 	glutDisplayFunc(display);
 	glutMouseFunc(mouseFunc);

 	glutMainLoop();
 	return 0;
}
