#include <windows.h>
#include <GL/glut.h>
static int window;
static int menu_id;
static int submenu_id;
static int value = 0;
void menu(int num)
{
    if(num == 0)
    {
        glutDestroyWindow(window);
        exit(0);
    }
    else
    {
        value = num;
    }
    glutPostRedisplay();
}

void createMenu(void)
{
    submenu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Translation", 2);
    glutAddMenuEntry("Reflection", 3);
    glutAddMenuEntry("Rotation", 4);
    glutAddMenuEntry("Scaling", 5);
    glutAddMenuEntry("Shearing",6);
    menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Clear", 1);
    glutAddSubMenu("2-D Transformations", submenu_id);
    glutAddMenuEntry("Quit", 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    if(value == 1)
    {
        return; //glutPostRedisplay();
    }
    else if(value == 2)
    {
        glPushMatrix();
        glColor3d(1.0, 0.0, 0.0);
        glutWireSphere(0.5, 50, 50);
        glPopMatrix();
    }
    else if(value == 3)
    {
        glPushMatrix();
        glColor3d(0.0, 1.0, 0.0);
        glRotated(65, -1.0, 0.0, 0.0);
        glutWireCone(0.5, 1.0, 50, 50);
        glPopMatrix();
    }
    else if(value == 4)
    {
        glPushMatrix();
        glColor3d(0.0, 0.0, 1.0);
        glutWireTorus(0.3,0.6,100,100);
        glPopMatrix();
    }
    else if(value == 5)
    {
        glPushMatrix();
        glColor3d(1.0, 0.0, 1.0);
        glutSolidTeapot(0.5);
        glPopMatrix();
    }
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    window = glutCreateWindow("Creating Menus");
    createMenu();
    glClearColor(0.0,0.0,0.0,0.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return EXIT_SUCCESS;
}
