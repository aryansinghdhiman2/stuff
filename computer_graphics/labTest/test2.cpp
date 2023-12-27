#include <GL/freeglut.h> 
#include <iostream>
#include <cstdlib>
#include <array>
#include <cmath>
#include "./pointMatrix.hpp"

struct pointPair {
    double x;
    double y;
    pointPair(double a,double b): x(a),y(b) {}
    pointPair(): x(0),y(0) {}

};

int halfHeight;
int halfWidth;
double angle;
int number_of_rotations;
int length;
pointPair r_pivot;
std::array<std::array<int,3>,4> colors;

void display()
{
    pointPair start_point = {(double)length,0};

    double rotation_angle = angle;
    const double angle_rad = rotation_angle * M_PI / 180;
    const double angle_cos = cos(angle_rad);
    const double angle_sin = sin(angle_rad);

    pointMatrix<3,3> rotation = {{angle_cos,-angle_sin,r_pivot.x*(1-angle_cos)+r_pivot.y*angle_sin},
                                {angle_sin,angle_cos ,r_pivot.y*(1-angle_cos)-r_pivot.x*angle_sin},
                                {0         ,0        ,1                                          }};

    pointMatrix<3,1> point_matrix = {{0},{0},{0}};

    int true_number_of_rots = 0;
    if((360 / rotation_angle) < number_of_rotations )
    {
        true_number_of_rots = 360 / rotation_angle;
    }
    else
    {
        true_number_of_rots = number_of_rotations;
    }
    int color_counter = 0;
    for(int i=0;i<true_number_of_rots;i++)
    {
        glColor3f(colors.at(color_counter).at(0),colors.at(color_counter).at(1),colors.at(color_counter).at(2));
        
        glBegin(GL_POLYGON);
        glVertex2d(r_pivot.x,r_pivot.y);
        glVertex2d(start_point.x,start_point.y);
        point_matrix = {{start_point.x},
                        {start_point.y},
                        {1.0}           };

        
        point_matrix = rotation * point_matrix;

        glVertex2d(point_matrix.at(0).at(0),point_matrix.at(1).at(0));
        start_point.x = point_matrix.at(0).at(0);
        start_point.y = point_matrix.at(1).at(0);
        glEnd();

        color_counter++;
        if(color_counter > 3)
        {
            color_counter = 0;
        }
    }
    // color_counter++;
    // if(color_counter > 3)
    // {
    //     color_counter = 0;
    // }
    glFlush();
    // Sleep(1000);
    // glutPostRedisplay();
}

int main(int argc, char **argv)
{
    std::cout<<"Enter Angle: ";
    std::cin>>angle;

    std::cout<<"Enter Number of Rotations: ";
    std::cin>>number_of_rotations;

    std::cout<<"Enter Length of Line: ";
    std::cin>>length;

    std::cout<<"Enter Pivot: ";
    std::cin>>r_pivot.x>>r_pivot.y;
    // angle = 45;
    // number_of_rotations = 18;
    // length = 50;
    // r_pivot.x = 0;
    // r_pivot.y = 0;
    colors.at(0) = {1,0,0};
    colors.at(1) = {0,1,0};
    colors.at(2) = {0,0,1};
    colors.at(3) = {0,1,1};
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