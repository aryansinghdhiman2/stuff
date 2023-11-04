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

void drawPolygon(int number_of_points,int radius,double tilt)
{
    glBegin(GL_LINE_LOOP);
    for(unsigned i=0;i<number_of_points;i++)
    {
        const double angle = 2 * M_PI * ((float)i/number_of_points) + tilt;
        const double x = radius * std::cos(angle);
        const double y = radius * std::sin(angle);
        glVertex2d(x,y);
    }
    glEnd();
}

void display()
{
    // drawAxes();
    static bool once = false;
    int number_of_polygons = 4;
    double tilt = (M_PI / 180) * 30;
    int seperation = 20;
    int diagonal = 20;
    int number_of_vertices = 4;
    if(not once)
    {
        double t = tilt;
        int d = diagonal;
        for(unsigned i = 0;i < number_of_polygons;i++)
        {
            drawPolygon(number_of_vertices,d,t);
            t+=tilt;
            d+=seperation;
        }
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