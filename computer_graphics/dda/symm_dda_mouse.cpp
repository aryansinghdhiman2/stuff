#include <GL/freeglut.h> // GLUT, includes glu.h and gl.h
#include <iostream>
#include <cmath>
#include <stdlib.h>

int halfHeight;
int halfWidth;

struct pointPair {
    double x;
    double y;
};

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

void symmetericalDDA(pointPair a,pointPair b)
{
    float delta_x = b.x-a.x;
    float delta_y = b.y-a.y;

    int n = std::round(log2(std::max(abs(delta_x),abs(delta_y))));
    float epsilon = std::pow(2,-n);
    int line_length_estimate = std::pow(2,n);

    float x_increment = epsilon * delta_x;
    float y_increment = epsilon * delta_y;
    pointPair currentPos = a;
    glPointSize(1);
    
    glBegin(GL_POINTS);
 
        glVertex2i(a.x,a.y);
        glVertex2i(b.x,b.y);
 
    for(int i = 1; i<line_length_estimate;i++)
    {
        currentPos.x += x_increment;
        currentPos.y += y_increment;
        glVertex2i(std::round(currentPos.x),std::round(currentPos.y));
    }
 
    glEnd();
    glFlush();
}

void mouseCallback(int button,int state,int x,int y)
{
    glColor3d(0.0f,0.0f,1.0f);
    static pointPair currentPos = {0,0};
    int adjusted_x = x - halfWidth;
    int adjusted_y = -(y - halfHeight);
    if(button == GLUT_LEFT_BUTTON and state == GLUT_DOWN)
    {
        symmetericalDDA(currentPos,{double(adjusted_x),double(adjusted_y)});
    }
    currentPos = {double(adjusted_x),double(adjusted_y)};
    glFlush();
}

void display()
{
    drawAxes();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(-1, -1);
    glutCreateWindow("OpenGL Setup Test");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    halfHeight = glutGet(GLUT_WINDOW_HEIGHT)/2; 
    halfWidth = glutGet(GLUT_WINDOW_WIDTH)/2;
    gluOrtho2D(-halfWidth, halfWidth, -halfHeight, halfHeight);

    glutDisplayFunc(display);
    glutMouseFunc(mouseCallback);
    glutMainLoop();
    return 0;
}