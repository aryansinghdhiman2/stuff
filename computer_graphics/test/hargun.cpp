#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <GL/glui.h>
#include <cmath>
GLUI *glui;  

const int WIDTH = 640;
const int HEIGHT = 480;

float side;

struct Point
{
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

std::vector<Point> points;

void drawCircle(int x, int y, int radius)
{
    int num_segments = 100;
    glBegin(GL_LINE_LOOP); // Use GL_LINE_LOOP to draw a hollow circle
    glColor3f(1.0, 1.0, 1.0); // Set color to white
    for (int i = 0; i < num_segments; i++)
    {
        float theta = 2.0f * M_PI * float(i) / float(num_segments);
        float dx = radius * cosf(theta);
        float dy = radius * sinf(theta);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}

void square(float x, float y) {
    glutSwapBuffers();
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + side, y);
    glVertex2f(x + side, y + side);
    glVertex2f(x, y + side);

    glEnd();
    drawCircle(x,y,side/2);
    drawCircle(x + side ,y,side/2);
    drawCircle(x + side ,y+side,side/2);
    drawCircle(x,y+side,side/2);

    glutSwapBuffers();
}




void mouseCallback(int button, int state, int x, int y) {

    x = x - (glutGet(GLUT_WINDOW_WIDTH) / 2);
    y = -(y - (glutGet(GLUT_WINDOW_HEIGHT) / 2));
   
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
         
        square(x,y);
        // drawSquareWithCircle(x,y);
        glutPostRedisplay();

}
}

void display() {
    // glClear(GL_COLOR_BUFFER_BIT);
    glPushAttrib(GL_CURRENT_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);

    glutSwapBuffers();
    glBegin(GL_LINES);
    glVertex2f(-320, 0);
    glVertex2f(320, 0);

    glVertex2f(0, -240);
    glVertex2f(0, 240);
    glEnd();
    glutSwapBuffers();
   

    glPopAttrib();
    // glutSwapBuffers();
    // glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("OpenGL Polygon Drawing");

    glui = GLUI_Master.create_glui("Area Filling");

    GLUI_Panel *panel = glui->add_panel("Select the square parameters");
    GLUI_Spinner *sideSpinner = glui->add_spinner_to_panel(panel, "Side:", GLUI_SPINNER_FLOAT, &side, 0);
    // GLUI_Spinner *posXSpinner = glui->add_spinner_to_panel(panel, "PosX:", GLUI_SPINNER_FLOAT, &posX, 0);
    // GLUI_Spinner *posYSpinner = glui->add_spinner_to_panel(panel, "PosY:", GLUI_SPINNER_FLOAT, &posY, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    auto halfHeight = glutGet(GLUT_WINDOW_HEIGHT)/2;
    auto halfWidth = glutGet(GLUT_WINDOW_WIDTH)/2;
    gluOrtho2D(-halfWidth, halfWidth, -halfHeight, halfHeight);
    GLUI_Master.set_glutMouseFunc(mouseCallback);
    glutDisplayFunc(display);

    // glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutMainLoop();

    return 0;
}