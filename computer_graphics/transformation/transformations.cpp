#include <GL/freeglut.h> // GLUT, includes glu.h and gl.h
#include <GL/glui.h>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <stack>
#include <array>
#include <algorithm>
#include "pointMatrix.hpp"

struct pointPair {
    double x;
    double y;
};

struct linePair {
    pointPair start;
    pointPair end;
};

typedef std::array<float,3> color;

int halfHeight;
int halfWidth;
int red_val = 255,blue_val = 255,green_val = 255;
bool draw = false;

std::vector<linePair> polygon;
std::vector<pointPair> polygon_points;

GLUI_Button* translate_button;

std::vector<pointPair> bresenham(pointPair a,pointPair b)
{
    std::vector<pointPair> points;

    float delta_x = b.x-a.x;
    float delta_y = b.y-a.y;

    int bigger_delta,smaller_delta;
    if(abs(delta_y)/abs(delta_x) < 1) 
    {
        bigger_delta = delta_x;
        smaller_delta = delta_y;
    }
    else
    {
        bigger_delta = delta_y;
        smaller_delta = delta_x;
    }

    int pk = 2 * abs(smaller_delta) - abs(bigger_delta);
    pointPair currentPoint = a;

    points.push_back(currentPoint);

    glColor3d(red_val/255.0,green_val/255.0,blue_val/255.0);
    glBegin(GL_POINTS);
    glVertex2d(a.x,a.y);

    for(int i = 0; i < abs(int(bigger_delta));i++)
    {
        if(pk >= 0.0)
        {
            currentPoint.x = delta_x >=0 ? currentPoint.x+1 : currentPoint.x-1;
            currentPoint.y = delta_y >=0 ? currentPoint.y+1 : currentPoint.y-1;
            pk = pk + 2 * abs(smaller_delta) - 2 * abs(bigger_delta);
        }
        else
        {
            if(abs(delta_y) > abs(delta_x))
            {
                currentPoint.y = delta_y >=0 ? currentPoint.y+1 : currentPoint.y-1;
            }
            else
            {
                currentPoint.x = delta_x >=0 ? currentPoint.x+1 : currentPoint.x-1;
            }
            pk = pk + 2 * abs(smaller_delta);
        }

        glVertex2d(currentPoint.x,currentPoint.y);
        points.push_back(currentPoint);
    }

    glEnd();
    glFlush();

    return points;
}


void mouseCallback(int button,int state,int x,int y)
{
    glColor3d(1.0f,1.0f,1.0f);
    int adjusted_x = x - halfWidth;
    int adjusted_y = -(y - halfHeight);
    static pointPair previousPoint;

    if(button == GLUT_LEFT_BUTTON and state == GLUT_DOWN)
    {
        if(not draw)
        {
            draw = true;
            previousPoint = {(double)adjusted_x,(double)adjusted_y};
        }
        else 
        {
            linePair line = {previousPoint,{(double)adjusted_x,(double)adjusted_y}};
            auto points = bresenham(line.start,line.end);
            polygon.push_back(line);
            polygon_points.insert(polygon_points.end(),points.begin(),points.end());
        }
        previousPoint = {(double)adjusted_x,(double)adjusted_y};
    }
    else if(button == GLUT_RIGHT_BUTTON and state == GLUT_DOWN and draw and polygon.size() > 1)
    {
        auto points = bresenham(polygon.back().end,polygon.front().start);
        polygon.push_back({polygon.back().end,polygon.front().start});
        polygon_points.insert(polygon_points.end(),points.begin(),points.end());
    }
    glFlush();
}

void translate_callback(const int i)
{
    double tx=0;
    double ty=0;

    myMatrix<3,3> translation = {{1,0,tx},
                                 {0,1,ty},
                                 {0,0,1}};

    myMatrix<3,2> point_matrix = {{0},{0},{0}};
    for(linePair& line : polygon)
    {
        point_matrix = {{line.start.x,line.end.x},
                        {line.start.y,line.end.y},
                        {1.0         ,1.0       }};

        point_matrix = translation * point_matrix;

        line.start.x = point_matrix.at(0).at(0);
        line.start.y = point_matrix.at(1).at(0);

        line.end.x = point_matrix.at(0).at(1);
        line.end.y = point_matrix.at(1).at(1);
        bresenham(line.start,line.end);
    }

    glFlush();

}

void rotate_callback(const int i)
{
    double rotation_angle = 30;
    const double angle_rad = rotation_angle * M_PI / 180;
    pointPair r_pivot;

    const double angle_cos = cos(angle_rad);
    const double angle_sin = sin(angle_rad);

    myMatrix<3,3> rotation = {{angle_cos,angle_sin,r_pivot.x*(1-angle_cos)+r_pivot.y*angle_sin},
                              {angle_sin,angle_cos,r_pivot.y*(1-angle_cos)-r_pivot.x*angle_sin},
                              {0         ,0       ,1                                          }};
    
    myMatrix<3,2> point_matrix = {{0},{0},{0}};
    for(linePair& line : polygon)
    {
        point_matrix = {{line.start.x,line.end.x},
                        {line.start.y,line.end.y},
                        {1.0         ,1.0       }};

        point_matrix = rotation * point_matrix;

        line.start.x = point_matrix.at(0).at(0);
        line.start.y = point_matrix.at(1).at(0);

        line.end.x = point_matrix.at(0).at(1);
        line.end.y = point_matrix.at(1).at(1);
        bresenham(line.start,line.end);
    }

    glFlush();
}

void scale_callback(const int i)
{
    double sx = 1;
    double sy = 1;
    double scaling_angle = 0;
    
    const double angle_rad = scaling_angle * M_PI / 180;
    const double angle_cos = cos(angle_rad);
    const double angle_sin = sin(angle_rad);
    const double angle_cos2 = pow(angle_cos,2);
    const double angle_sin2 = pow(angle_sin,2);
    const double angle_cos_sin = angle_cos * angle_sin;
    pointPair s_pivot;

    const double top_right = s_pivot.y*(sx-sy)*angle_cos_sin-sx*s_pivot.x*angle_cos2-sy*s_pivot.x*angle_sin2+s_pivot.x;
    const double middle_right = s_pivot.x*(sx-sy)*angle_cos_sin-sx*s_pivot.y*angle_sin2-sy*s_pivot.y*angle_cos2+s_pivot.y;

    myMatrix<3,3> scaling = {{sx*angle_cos2+sy*angle_sin2 ,(sy-sx)*angle_cos_sin      ,top_right   },
                             {(sy-sx)*angle_cos_sin       ,sx*angle_sin2+sy*angle_cos2,middle_right},
                             {0                           ,0                          ,1           }};
    
    myMatrix<3,2> point_matrix = {{0},{0},{0}};
    for(linePair& line : polygon)
    {
        point_matrix = {{line.start.x,line.end.x},
                        {line.start.y,line.end.y},
                        {1.0         ,1.0       }};

        point_matrix = scaling * point_matrix;

        line.start.x = point_matrix.at(0).at(0);
        line.start.y = point_matrix.at(1).at(0);

        line.end.x = point_matrix.at(0).at(1);
        line.end.y = point_matrix.at(1).at(1);
        bresenham(line.start,line.end);
    }

    glFlush();
}

void transform_callback(const int i)
{
    double tx=0;
    double ty=0;

    double rotation_angle = 30;
    double r_angle_rad = rotation_angle * M_PI / 180;
    pointPair r_pivot;

    double sx = 1;
    double sy = 1;
    double scaling_angle = 0;
    double s_angle_rad = scaling_angle * M_PI / 180;

    pointPair scaling_pivot_point;

    myMatrix<3,3> translation = {{1,0,tx},
                                 {0,1,ty},
                                 {0,0,1}};

    myMatrix<3,3> rotation = {{cos(r_angle_rad),-sin(r_angle_rad),r_pivot.x*(1-cos(r_angle_rad))+r_pivot.y*sin(r_angle_rad)},
                              {sin(r_angle_rad),cos(r_angle_rad), r_pivot.y*(1-cos(r_angle_rad))-r_pivot.x*sin(r_angle_rad)},
                              {0         ,0         , 1}};

    myMatrix<3,3> scaling = {{sx,0,0},
                             {0,sy,0},
                             {0,0,1}};

    myMatrix<3,2> point_matrix = {{0},{0},{0}};
    for(linePair& line : polygon)
    {
        point_matrix = {{line.start.x,line.end.x},
                        {line.start.y,line.end.y},
                        {1.0         ,1.0       }};

        point_matrix = point_matrix;

        line.start.x = point_matrix.at(0).at(0);
        line.start.y = point_matrix.at(1).at(0);

        line.end.x = point_matrix.at(0).at(1);
        line.end.y = point_matrix.at(1).at(1);
        bresenham(line.start,line.end);
    }

    glFlush();
}

void display()
{
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(-1, -1);
    int main_window = glutCreateWindow("Filling");

    GLUI_Master.set_glutIdleFunc(nullptr);
    GLUI_Master.set_glutMouseFunc(mouseCallback);
    GLUI_Master.set_glutDisplayFunc(display);
    GLUI *gluiWindow = GLUI_Master.create_glui_subwindow(main_window,GLUI_SUBWINDOW_TOP);
    gluiWindow->set_main_gfx_window(main_window);

    translate_button = gluiWindow->add_button("Translate",-1,transform_callback);

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