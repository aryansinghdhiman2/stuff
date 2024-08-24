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

std::vector<pointPair> generatePolygonPoints(int number_of_points,int radius)
{
    std::vector<pointPair> vertices;
    vertices.reserve(number_of_points);
    for(unsigned i=0;i<number_of_points;i++)
    {
        const double angle = 2 * M_PI * ((float)i/(float)number_of_points);
        const double x = radius * std::cos(angle);
        const double y = radius * std::sin(angle);
        vertices.emplace_back(x,y);
    }
    return vertices;
}

void drawPattern(const std::vector<pointPair>& vertices)
{
    for(unsigned i = 0;i<vertices.size();i++)
    {
        for(unsigned j = 0;j<vertices.size();j++)
        {
            glBegin(GL_LINES);
            glVertex2d(vertices.at(i).x,vertices.at(i).y);
            glVertex2d(vertices.at(j).x,vertices.at(j).y);
            glEnd();
        }
    }


    glFlush();
}
bool once = false;
void display()
{
    // drawAxes();
    if(not once)
    {
        const auto vertices = generatePolygonPoints(7,200);
        drawPattern(vertices);
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