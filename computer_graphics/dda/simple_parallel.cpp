#include <iostream>
#include <GL/freeglut.h>
#include <cmath>

using namespace std;

int clickCount = 0;
int x_start, x_end, y_start, y_end;

void myInit()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-300, 300.0, -300.0, 300.0);
}

void simple_dda(int x1, int y1, int x2, int y2)
{
    cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << endl;
    int dx, dy, step;
    float x, y, x_inc, y_inc;

    dx = x2 - x1;
    dy = y2 - y1;

    step = max(abs(dx), abs(dy));

    x_inc = float(dx) / float(step);
    y_inc = float(dy) / float(step);

    x = x1;
    y = y1;
    glPointSize(1);

    glBegin(GL_POINTS);

    glVertex2i(x1, y1);
    glVertex2i(x2, y2);

    for (int k = 0; k < step; k++)
    {
        x = x + x_inc;
        y = y + y_inc;
        glVertex2i(round(x), round(y));
    }
    glEnd();
    glFlush();
}

void parallelLine(int x1, int y1, int x2, int y2, int distance)
{
    simple_dda(x1, y1 + distance, x2, y2 + distance);
}

void myScreen()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_LINES);
    glVertex2i(300, 0);
    glVertex2i(-300, 0);
    glVertex2i(0, 300);
    glVertex2i(0, -300);

    glEnd();

    if (clickCount == 2)
    {
        simple_dda(x_start, y_start, x_end, y_end);
        parallelLine(x_start, y_start, x_end, y_end, 1);
    }
    glFlush();
}

void myMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if (clickCount == 0)
        {
            x_start = x - 300;
            y_start = 300 - y;
            clickCount++;
        }
        else if (clickCount == 1)
        {
            x_end = x - 300;
            y_end = 300 - y;
            clickCount++;
        }
        glutPostRedisplay();
    }
}

int main(int argc, char **argv)
{
    // Initalising GLUT and creating a window
    // Intialise Open-GL Toolkit
    glutInit(&argc, argv);
    // Allocates a single display buffer and uses color to draw
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // Making of Window
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow("SIMPLE DDA LINE DRAWING ALGORITHM");

    myInit();

    glutDisplayFunc(myScreen);
    // Processing Input Clicks
    glutMouseFunc(myMouse);

    // Endless loop
    glutMainLoop();

    return 0;
}