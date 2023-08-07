#include <GL/freeglut.h> // GLUT, includes glu.h and gl.h
#include <iostream>
#include<utility>
#include<cmath>
#include <stdlib.h>
#define INTERPIXEL_DISTANCE 0.001

bool floatAreSame(float a,float b)
{
    return std::fabs(a-b) < INTERPIXEL_DISTANCE;
}

struct pointPair {
    float x;
    float y;
    bool operator==(const pointPair& other)
    {
        if(floatAreSame(other.x,this->x) and floatAreSame(other.y,this->y)) return true;
        else return false;
    }
    bool operator!=(const pointPair& other)
    {
        return not this->operator==(other);
    }
};

void drawAxes()
{
    glLineWidth(1.0f);
    glColor3d(1.0f,1.0f,1.0f);
    glBegin(GL_LINES);
        glVertex2i(1,0);
        glVertex2i(-1,0);
        glVertex2i(0,1);
        glVertex2i(0,-1);
    glEnd();
}

void dda(pointPair a,pointPair b)
{
    float delta_x = b.x-a.x;
    float delta_y = b.y-a.y;

    float epsilon = INTERPIXEL_DISTANCE / (std::max(abs(delta_x),abs(delta_y)));

    glBegin(GL_POINTS);
        glVertex2f(a.x,a.y);
        glVertex2f(b.x,b.y);
    glEnd();

    pointPair currentPos = a;
    while(currentPos!=b)
    {
        currentPos.x += epsilon * delta_x;
        currentPos.y += epsilon * delta_y;

        glPointSize(3);
        glBegin(GL_POINTS);
            glVertex2f(currentPos.x,currentPos.y);
        glEnd();
    }
}

void mouseCallback(int button,int state,int x,int y)
{
    
    static pointPair currentPos = {0,0};
    float halfHeight = float(glutGet(GLUT_WINDOW_HEIGHT)/2);
    float halfWidth = float(glutGet(GLUT_WINDOW_WIDTH))/2;
    float adjusted_x = (x/ halfWidth)-1.0;
    float adjusted_y = -((y/halfHeight)-1.0);
    if(button == GLUT_LEFT_BUTTON and state == GLUT_DOWN)
    {
        glColor3d(0.0f,0.0f,1.0f);
        dda(currentPos,{adjusted_x,adjusted_y});
    }
    currentPos = {adjusted_x,adjusted_y};
    glFlush();
}

void display()
{

    drawAxes();
    glPointSize(10);
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 320);
    glutInitWindowPosition(-1, -1);
    glutCreateWindow("OpenGL Setup Test");
    glutDisplayFunc(display);
    glutMouseFunc(mouseCallback);
    glutMainLoop();
    return 0;
}