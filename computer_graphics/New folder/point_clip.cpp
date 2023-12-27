//necessary headers included
#include <GL/freeglut.h>
#include <GL/glui.h>
#include <iostream>
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
int pointIndex = 0;

//responsible for clip window drawing
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    glVertex2f(xmin, ymin);
    glVertex2f(xmin, ymax);
    glVertex2f(xmax, ymax);
    glVertex2f(xmax, ymin);
    glVertex2f(xmin, ymax);
    glVertex2f(xmax, ymax);
    glVertex2f(xmin, ymin);
    glVertex2f(xmax, ymin);
    glEnd();
    glFlush();
}

//used to draw point on the screen 
void draw_point(int x, int y) {
    if (x >= xmin && x <= xmax && y >= ymin && y <= ymax) {
        glColor3d(0.0, 1.0, 0.0);//green if point is insides the window
    } else {
        glColor3d(1.0, 0.0, 0.0);//red if the point is outside the window
    }

    glPointSize(5.0);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
    glFlush();
}

//handles which function to call on mouse click
void callback_mouse_button(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        int adjusted_x = x - halfWidth;
        int adjusted_y = -(y - halfHeight);

        cout << adjusted_x << "," << adjusted_y << endl;
        vertx.push_back(adjusted_x);
        verty.push_back(adjusted_y);

        draw_point(adjusted_x, adjusted_y);
    }
}

//intiailizes glut
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(10, 10);
    int main_window = glutCreateWindow("Point Display");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    halfHeight = glutGet(GLUT_WINDOW_HEIGHT) / 2;
    halfWidth = glutGet(GLUT_WINDOW_WIDTH) / 2;
    glViewport(0, 0, halfWidth * 2, halfHeight * 2);
    gluOrtho2D(-halfWidth, halfWidth, -halfHeight, halfHeight);

    glutDisplayFunc(display);
    glutMouseFunc(callback_mouse_button);

    glutMainLoop();

    return 0;
}