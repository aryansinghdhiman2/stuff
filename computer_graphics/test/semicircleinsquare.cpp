#include <GL/freeglut.h> // GLUT, includes glu.h and gl.h
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <bitset>
#include <vector>
#include <algorithm>


struct pointPair {
    double x;
    double y;
    pointPair(double a,double b): x(a),y(b) {}
    pointPair(): x(0),y(0) {}

};

int red_val = 255,blue_val = 255,green_val = 255;
int halfHeight;
int halfWidth;


void drawAxes()
{
    glLineWidth(1.0f);
    glColor3d(1.0f,1.0f,1.0f);
    glBegin(GL_LINES);
        glVertex2i(halfWidth,0);
        glVertex2i(-halfWidth,0);
        glVertex2i(0,halfHeight);
        glVertex2i(0,-halfHeight);
    glEnd();
}

void drawSquare(int x,int y,int side)
{
    glBegin(GL_LINE_LOOP);
    glVertex2i(x+side/2,y-side/2);
    glVertex2i(x+side/2,y+side/2);
    glVertex2i(x-side/2,y+side/2);
    glVertex2i(x-side/2,y-side/2);
    glEnd();
}

void drawCircle(int center_x,int center_y,int radius)
{
    int segments = 100;
    glBegin(GL_LINE_LOOP);
    for(unsigned i=0;i<segments;i++)
    {
        double angle = 2 * M_PI * ((double)i/segments);
        double x = radius * cos(angle);
        double y = radius * sin(angle);

        glVertex2d(center_x+x,center_y+y);
    }
    glEnd();
}

void drawSemiCircle(int center_x,int center_y,int radius,double start_angle)
{
    int segments = 100;
    glBegin(GL_LINE_LOOP);
    for(unsigned i=0;i<=segments/2;i++)
    {
        double angle = 2 * M_PI * ((double)i/segments) + start_angle;
        double x = radius * cos(angle);
        double y = radius * sin(angle);

        glVertex2d(center_x+x,center_y+y);
    }
    glEnd();
}


void display()
{
    // drawAxes();
    static bool once = false;
    int x = 0;
    int y = 0;
    int side = 200;
    if(not once)
    {
        drawSquare(x,y,side);
        drawSemiCircle(x+side/2,y,side/2,(M_PI/180)*270);
        drawSemiCircle(x-side/2,y,side/2,(M_PI/180)*90);
        drawSemiCircle(x,y+side/2,side/2,(M_PI/180)*0);
        drawSemiCircle(x,y-side/2,side/2,(M_PI/180)*180);

        drawSemiCircle(x+side/2,y,side/2,(M_PI/180)*90);
        drawSemiCircle(x-side/2,y,side/2,(M_PI/180)*270);
        drawSemiCircle(x,y+side/2,side/2,(M_PI/180)*180);
        drawSemiCircle(x,y-side/2,side/2,(M_PI/180)*0);
        once = true;
    }
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(-1, -1);
    int main_window = glutCreateWindow("Circle");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    halfHeight = glutGet(GLUT_WINDOW_HEIGHT)/2;
    halfWidth = glutGet(GLUT_WINDOW_WIDTH)/2;
    gluOrtho2D(-halfWidth, halfWidth, -halfHeight, halfHeight);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}