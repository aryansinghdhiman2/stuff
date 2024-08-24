//necassary header files
#include <GL/freeglut.h>
#include <GL/glui.h>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

//declaration of global variables
int halfHeight;
int halfWidth;
const int xmin = -150;
const int xmax = 150;
const int ymin = -150;
const int ymax = 150;
vector<int> vertx;
vector<int> verty;
int start = 0;

//GLUI button pointers for submenu
GLUI_Button *cohen_button;
GLUI_Button *barsky_button;
GLUI_Button *clear_screen_button;

//responsible for clipping window 
void display()
{
    glColor3f(1.0, 1.0, 1.0);//sets color white
    glBegin(GL_LINES);
    glVertex2f(xmin, ymin);
    glVertex2f(xmin, ymax);
    glVertex2f(xmax, ymax);
    glVertex2f(xmax, ymin);
    glVertex2f(xmin, ymax);
    glVertex2f(xmax, ymax);
    glVertex2f(xmin, ymin);
    glVertex2f(xmax, ymin);

    glEnd();   // stored in frame buffer
    glFlush(); // flushing from frame buffer to display
}

//algorithm for liang barsky line clipping
void Liang_Barsky()
{
    int dx = vertx[start + 1] - vertx[start];
    int dy = verty[start + 1] - verty[start];
    double p[4], q[4];
    p[0] = -dx;
    q[0] = vertx[start] - xmin;
    p[1] = dx;
    q[1] = xmax - vertx[start];
    p[2] = -dy;
    q[2] = verty[start] - ymin;
    p[3] = dy;
    q[3] = ymax - verty[start];

    double u1 = 0.0;
    double u2 = 1.0;
    for (int i = 0; i < 4; i++)
    {
        if (p[i] == 0 && q[i] < 0)
        {
            return;
        }

        if (p[i] < 0)
        {
            double t = q[i] / p[i];
            if (t > u1)
                u1 = t;
        }
        else if (p[i] > 0)
        {
            double t = q[i] / p[i];
            if (t < u2)
                u2 = t;
        }
    }

    if (u1 < u2)
    {
        int clipped_x0 = vertx[start] + u1 * dx;
        int clipped_y0 = verty[start] + u1 * dy;
        int clipped_x1 = vertx[start] + u2 * dx;
        int clipped_y1 = verty[start] + u2 * dy;

        // Draw the clipped line
        glColor3f(255, 255, 0.0);
        glLineWidth(2.7f);
        glBegin(GL_LINES);
        glVertex2f(clipped_x0, clipped_y0);
        glVertex2f(clipped_x1, clipped_y1);
        glEnd();
        glFlush();
    }
    start = start + 2;
    if (start >= vertx.size() || start >= verty.size())
    {
        start = 0; // Reset start to 0 if vectors are exhausted
    }
}

//calculates the region code foe a given point
int computeCode(double x, double y)
{
    int code = 0;

    // left
    if (x < xmin)
    {
        code |= 1;
    }
    // right
    if (x > xmax)
    {
        code |= 2;
    }
    // bottom
    if (y < ymin)
    {
        code |= 4;
    }
    // top
    if (y > ymax)
    {
        code |= 8;
    }

    return code;
}

//algorithm fro cohen sutherland line clipping
void cohenSutherlandClip(double x1, double y1, double x2, double y2)
{
    cout << "line Clip" << endl;
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);

    cout << code1 << " " << code2 << endl;

    while (true)
    {
        if (!(code1 | code2))
        {
            // Both points lie inside the clip window
            glLineWidth(2.7f);
            glColor3f(0.0, 1.0, 0.0);
            glBegin(GL_LINES);
            glVertex2f(x1, y1);
            glVertex2f(x2, y2);
            glEnd();
            glFlush();
            break;
        }
        else if (code1 & code2)
        {
            // Both points are outside the same region, so the line is completely outside
            break;
        }
        else
        {
            // Line needs to be clipped
            int codeClipped = code1 ? code1 : code2;
            double x, y;
            if (codeClipped & 8)
            {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            }
            else if (codeClipped & 4)
            {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            }
            else if (codeClipped & 2)
            {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            }
            else
            {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            if (codeClipped == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }
    start = start + 2;
    if (start >= vertx.size() || start >= verty.size())
    {
        start = 0; // Reset start to 0 if vectors are exhausted
    }
}

//used to draw the line which will be later clipped
void draw_line()
{
    glLineWidth(1.7f);
    glColor3d(1, 0, 0);

    glBegin(GL_LINES);
    glVertex2f(vertx[start], verty[start]);
    glVertex2f(vertx[start + 1], verty[start + 1]);
    glEnd();

    // start ++;
    glFlush();
}

//handles which function to run during mouse click
void callback_mouse_button(int button, int state, int x, int y)
{
    static int count = 1;
    int adjusted_x = x - halfWidth;
    int adjusted_y = -(y - halfHeight);
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        cout << adjusted_x << "," << adjusted_y << endl;
        if (vertx.size() + verty.size() == 0)
        {
            vertx.push_back(adjusted_x);
            verty.push_back(adjusted_y);
        }
        else if (vertx.size() + verty.size() >= 2)
        {
            vertx.push_back(adjusted_x);
            verty.push_back(adjusted_y);
            draw_line();
        }
    }
}

//called when CLEAR button on submenu is clicked and removes the current line form board
void clearScreenCallback(int id)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glutPostRedisplay();
    vertx.clear();
    verty.clear();
}
//called when cohensutherland button on submenu is clicked 
void cohenCallback(const int id)
{
    cohenSutherlandClip(vertx[start], verty[start], vertx[start + 1], verty[start + 1]);
}

//called when liangbarsky button on the submenu is clicked
void BarskyCallback(const int id)
{
    Liang_Barsky();
}


//main function the initializes GLUT
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(10, 10);
    int main_window = glutCreateWindow("Fiiling Algorithms");
    // glutMouseFunc(callback_mouse_button);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    halfHeight = glutGet(GLUT_WINDOW_HEIGHT) / 2;
    halfWidth = glutGet(GLUT_WINDOW_WIDTH) / 2;
    glViewport(0, 0, halfWidth * 2, halfHeight * 2);
    gluOrtho2D(-halfWidth, halfWidth, -halfHeight, halfHeight);

    GLUI_Master.set_glutIdleFunc(nullptr);
    GLUI_Master.set_glutMouseFunc(callback_mouse_button);
    GLUI *gluiWindow = GLUI_Master.create_glui_subwindow(main_window, GLUI_SUBWINDOW_TOP);
    gluiWindow->set_main_gfx_window(main_window);
    gluiWindow->add_column(false);

    cohen_button = gluiWindow->add_button("CLIP USING COHEN SUTHERLAND ALGO", -1, cohenCallback);
    gluiWindow->add_column(true);

    barsky_button = gluiWindow->add_button("CLIP USING LIANG BARSKY ALGO", -1, BarskyCallback);

    gluiWindow->add_column(true);

    clear_screen_button = gluiWindow->add_button("CLEAR", -1, clearScreenCallback);

    glutDisplayFunc(display);
    glutMainLoop();
}