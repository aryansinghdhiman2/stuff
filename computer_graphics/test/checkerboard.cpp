#include <GL/freeglut.h> // GLUT, includes glu.h and gl.h
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <bitset>
#include <vector>
#include <array>

struct pointPair {
    double x;
    double y;
    pointPair(double a,double b): x(a),y(b) {}
    pointPair(): x(0),y(0) {}

};

using color = std::array<double,3>;

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

void drawCheckerboard(int height,int width,int number_of_checkers,color first,color second)
{
    int board_half_height = height/2;
    int board_half_width = width/2;
    int x_inc = width/number_of_checkers;
    int y_inc = height/number_of_checkers;

    bool invert_start_color = false;
    for(int y = -board_half_height;y<=board_half_height;y++)
    {
        if(y!=board_half_height and abs(y) % y_inc == 0)
        {
            invert_start_color = invert_start_color ? false : true;
        }
        bool change_color = invert_start_color ? true : false;
        
        int x = -board_half_width;
        glBegin(GL_LINES);
            if(change_color)
            {
                glColor3d(second[0],second[1],second[2]);
            }
            else
            {
                glColor3d(first[0],first[1],first[2]);
            }
            glVertex2i(x,y);
            while(x<board_half_width)
            {
                x+=x_inc;
                glVertex2i(x,y);
                glVertex2i(x+1,y);
                change_color = change_color ? false : true;
                if(change_color)
                {
                    glColor3d(second[0],second[1],second[2]);
                }
                else
                {
                    glColor3d(first[0],first[1],first[2]);
                }
            }

        glEnd();
    }
}

void display()
{
    // drawAxes();
    drawCheckerboard(200,200,8,{1,1,1},{0,0,0});
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(-1, -1);
    int main_window = glutCreateWindow("Circle");
    
    glShadeModel(GL_FLAT);
    
    glLoadIdentity();
    halfHeight = glutGet(GLUT_WINDOW_HEIGHT)/2;
    halfWidth = glutGet(GLUT_WINDOW_WIDTH)/2;
    gluOrtho2D(-halfWidth, halfWidth, -halfHeight, halfHeight);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}