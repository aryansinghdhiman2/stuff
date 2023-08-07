#include <GL/freeglut.h> // GLUT, includes glu.h and gl.h
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <vector>

int halfHeight;
int halfWidth;

struct pointPair {
    double x;
    double y;
};

std::vector<pointPair> points;

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

void simpleDDA(pointPair a,pointPair b)
{
    float delta_x = b.x-a.x;
    float delta_y = b.y-a.y;

    int line_length_estimate = (std::max(abs(delta_x),abs(delta_y)));
    float epsilon = 1 / float(line_length_estimate);
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


void display()
{
    drawAxes();
    glColor3d(0.0f,0.0f,1.0f);
    for(int i=0; i<points.size();i++)
    {
        if(i==0) 
        {
            simpleDDA({0,0},points.at(i));
        }
        else
        {
            simpleDDA(points.at(i-1),points.at(i));
        }
    }
    glFlush();
}

void getInput()
{
    std::cout<<"Enter number of points: ";
    int number_of_points;
    std::cin>>number_of_points;

    std::cout<<"Range of x is : ("<<-halfWidth<<","<<halfWidth<<")"<<std::endl;
    std::cout<<"Range of y is : ("<<-halfHeight<<","<<halfHeight<<")"<<std::endl;
    for(int i=0;i<number_of_points;i++)
    {
        int temp_x,temp_y;
        std::cout<<"Enter x and y: ";
        std::cin>>temp_x>>temp_y;
        points.push_back(pointPair{double(temp_x),double(temp_y)});
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(-1, -1);
    glutCreateWindow("Simple DDA Terminal");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    halfHeight = glutGet(GLUT_WINDOW_HEIGHT)/2;
    halfWidth = glutGet(GLUT_WINDOW_WIDTH)/2;
    gluOrtho2D(-halfWidth, halfWidth, -halfHeight, halfHeight);
    getInput();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}