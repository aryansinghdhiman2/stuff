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
// int red_val = 255,blue_val = 255,green_val = 255;
int red_val = 0,blue_val = 0,green_val = 0;
bool draw = false;

std::vector<linePair> polygon;

GLUI_Panel* color_panel;
GLUI_Spinner* red_spinner;
GLUI_Spinner* green_spinner;
GLUI_Spinner* blue_spinner;

GLUI_Button* translate_button;
GLUI_Button* rotate_button;
GLUI_Button* scale_button;
GLUI_Button* clear_button;

GLUI_Panel* translate_panel;
GLUI_EditText* tx_box;
GLUI_EditText* ty_box;

GLUI_Panel* rotate_panel;
GLUI_Spinner* rotation_spinner;
GLUI_EditText* r_pivot_x;
GLUI_EditText* r_pivot_y;

GLUI_Panel* scale_panel;
GLUI_EditText* x_scale;
GLUI_EditText* y_scale;
GLUI_Spinner* scaling_spinner;
GLUI_EditText* s_pivot_x;
GLUI_EditText* s_pivot_y;

GLUI_Panel* shear_panel;
GLUI_EditText* x_shear;
GLUI_EditText* y_shear;
GLUI_Button* shear_button;

GLUI_Panel* reflect_panel;
GLUI_Button* x_refl;
GLUI_Button* y_refl;

void drawAxes()
{
    glLineWidth(1.0f);
    // glColor3d(1.0f,1.0f,1.0f);
    glColor3d(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
        glVertex2i(halfWidth,0);
        glVertex2i(-halfWidth,0);
        glVertex2i(0,halfHeight);
        glVertex2i(0,-halfHeight);
    glEnd();
}

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
        }
        previousPoint = {(double)adjusted_x,(double)adjusted_y};
    }
    else if(button == GLUT_RIGHT_BUTTON and state == GLUT_DOWN and draw and polygon.size() > 1)
    {
        auto points = bresenham(polygon.back().end,polygon.front().start);
        polygon.push_back({polygon.back().end,polygon.front().start});
    }
    glFlush();
}

void translate_callback(const int i)
{
    double tx=tx_box->get_int_val();
    double ty=ty_box->get_int_val();

    pointMatrix<3,3> translation = {{1,0,tx},
                                    {0,1,ty},
                                    {0,0,1}};

    pointMatrix<3,2> point_matrix = {{0},{0},{0}};
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
    double rotation_angle = rotation_spinner->get_int_val();
    pointPair r_pivot;
    r_pivot.x = r_pivot_x->get_int_val();
    r_pivot.y = r_pivot_y->get_int_val();

    const double angle_rad = rotation_angle * M_PI / 180;
    const double angle_cos = cos(angle_rad);
    const double angle_sin = sin(angle_rad);

    pointMatrix<3,3> rotation = {{angle_cos,-angle_sin,r_pivot.x*(1-angle_cos)+r_pivot.y*angle_sin},
                                {angle_sin,angle_cos ,r_pivot.y*(1-angle_cos)-r_pivot.x*angle_sin},
                                {0         ,0        ,1                                          }};
    
    pointMatrix<3,2> point_matrix = {{0},{0},{0}};
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
    double sx = x_scale->get_float_val();
    double sy = y_scale->get_float_val();
    double scaling_angle = scaling_spinner->get_int_val();
    pointPair s_pivot;
    s_pivot.x = s_pivot_x->get_int_val();
    s_pivot.y = s_pivot_y->get_int_val();

    const double angle_rad = scaling_angle * M_PI / 180;
    const double angle_cos = cos(angle_rad);
    const double angle_sin = sin(angle_rad);
    const double angle_cos2 = pow(angle_cos,2);
    const double angle_sin2 = pow(angle_sin,2);
    const double angle_cos_sin = angle_cos * angle_sin;

    const double top_right = s_pivot.y*(sx-sy)*angle_cos_sin-sx*s_pivot.x*angle_cos2-sy*s_pivot.x*angle_sin2+s_pivot.x;
    const double middle_right = s_pivot.x*(sx-sy)*angle_cos_sin-sx*s_pivot.y*angle_sin2-sy*s_pivot.y*angle_cos2+s_pivot.y;

    pointMatrix<3,3> scaling = {{sx*angle_cos2+sy*angle_sin2 ,(sy-sx)*angle_cos_sin      ,top_right   },
                                {(sy-sx)*angle_cos_sin       ,sx*angle_sin2+sy*angle_cos2,middle_right},
                                {0                           ,0                          ,1           }};
    
    pointMatrix<3,2> point_matrix = {{0},{0},{0}};
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

void shear_callback(const int i)
{
    double shx = x_shear->get_float_val();
    double shy = y_shear->get_float_val();

    pointMatrix<3,3> shearing = {{1  ,shx,0},
                                 {shy,1  ,0},
                                 {0  ,0  ,1}};

    pointMatrix<3,2> point_matrix = {{0},{0},{0}};
    for(auto& line : polygon)
    {
        point_matrix = {{line.start.x,line.end.x},
                        {line.start.y,line.end.y},
                        {1.0         ,1.0       }};

        point_matrix = shearing * point_matrix;

        line.start.x = point_matrix.at(0).at(0);
        line.start.y = point_matrix.at(1).at(0);

        line.end.x = point_matrix.at(0).at(1);
        line.end.y = point_matrix.at(1).at(1);
        bresenham(line.start,line.end);
    }
}

void reflect_around_x(const int i)
{
    pointMatrix<3,3> reflection_x = {{1,0,0},{0,-1,0},{0,0,1}};

    pointMatrix<3,2> point_matrix = {{0},{0},{0}};

    for(auto& line : polygon)
    {
        point_matrix = {{line.start.x,line.end.x},
                        {line.start.y,line.end.y},
                        {1.0         ,1.0       }};

        point_matrix = reflection_x * point_matrix;

        line.start.x = point_matrix.at(0).at(0);
        line.start.y = point_matrix.at(1).at(0);

        line.end.x = point_matrix.at(0).at(1);
        line.end.y = point_matrix.at(1).at(1);
        bresenham(line.start,line.end);
    }
}

void reflect_around_y(const int i)
{
    pointMatrix<3,3> reflection_y = {{-1,0,0},{0,1,0},{0,0,1}};

    pointMatrix<3,2> point_matrix = {{0},{0},{0}};

    for(auto& line : polygon)
    {
        point_matrix = {{line.start.x,line.end.x},
                        {line.start.y,line.end.y},
                        {1.0         ,1.0       }};

        point_matrix = reflection_y * point_matrix;

        line.start.x = point_matrix.at(0).at(0);
        line.start.y = point_matrix.at(1).at(0);

        line.end.x = point_matrix.at(0).at(1);
        line.end.y = point_matrix.at(1).at(1);
        bresenham(line.start,line.end);
    }
}

void clear_callback(const int i)
{
    glClear(GL_COLOR_BUFFER_BIT);
    polygon.clear();
    draw = false;
    glutPostRedisplay();
}

void display()
{
    drawAxes();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 667);
    glutInitWindowPosition(480,100);
    int main_window = glutCreateWindow("Transformation");

    GLUI_Master.set_glutIdleFunc(nullptr);
    GLUI_Master.set_glutMouseFunc(mouseCallback);
    GLUI_Master.set_glutDisplayFunc(display);
    GLUI *gluiWindow = GLUI_Master.create_glui("Transformations",0,290,100);
    gluiWindow->set_main_gfx_window(main_window);

    translate_panel = gluiWindow->add_panel("Translation");
    tx_box = gluiWindow->add_edittext_to_panel(translate_panel,"X Displacement",GLUI_EDITTEXT_INT);
    ty_box = gluiWindow->add_edittext_to_panel(translate_panel,"Y Displacement",GLUI_EDITTEXT_INT);
    translate_button = gluiWindow->add_button_to_panel(translate_panel,"Translate",-1,translate_callback);

    
    rotate_panel = gluiWindow->add_panel("Rotation");
    rotation_spinner = gluiWindow->add_spinner_to_panel(rotate_panel,"Angle",GLUI_SPINNER_INT);
    r_pivot_x = gluiWindow->add_edittext_to_panel(rotate_panel,"Pivot X",GLUI_EDITTEXT_INT);
    r_pivot_y = gluiWindow->add_edittext_to_panel(rotate_panel,"Pivot Y",GLUI_EDITTEXT_INT);
    rotate_button = gluiWindow->add_button_to_panel(rotate_panel,"Rotate",-1,rotate_callback);
    rotation_spinner->set_int_limits(-360,360,GLUI_LIMIT_CLAMP);


    scale_panel = gluiWindow->add_panel("Scaling");
    x_scale = gluiWindow->add_edittext_to_panel(scale_panel,"X Scaling Factor",GLUI_EDITTEXT_FLOAT);
    y_scale = gluiWindow->add_edittext_to_panel(scale_panel,"Y Scaling Factor",GLUI_EDITTEXT_FLOAT);
    scaling_spinner = gluiWindow->add_spinner_to_panel(scale_panel,"Scaling Angle",GLUI_SPINNER_INT);
    s_pivot_x = gluiWindow->add_edittext_to_panel(scale_panel,"Pivot X",GLUI_EDITTEXT_INT);
    s_pivot_y = gluiWindow->add_edittext_to_panel(scale_panel,"Pivot Y",GLUI_EDITTEXT_INT);
    scale_button = gluiWindow->add_button_to_panel(scale_panel,"Scale",-1,scale_callback);
    scaling_spinner->set_int_limits(-360,360,GLUI_LIMIT_CLAMP);

    shear_panel = gluiWindow->add_panel("Shearing");
    x_shear = gluiWindow->add_edittext_to_panel(shear_panel,"X Shearing Factor",GLUI_EDITTEXT_FLOAT);
    y_shear = gluiWindow->add_edittext_to_panel(shear_panel,"Y Shearing Factor",GLUI_EDITTEXT_FLOAT);
    shear_button = gluiWindow->add_button_to_panel(shear_panel,"Shear",-1,shear_callback);

    reflect_panel = gluiWindow->add_panel("Reflection");
    x_refl = gluiWindow->add_button_to_panel(reflect_panel,"About X",-1,reflect_around_x);
    y_refl = gluiWindow->add_button_to_panel(reflect_panel,"About Y",-1,reflect_around_y);

    color_panel = gluiWindow->add_panel("Color");
    red_spinner = gluiWindow->add_spinner_to_panel(color_panel,"Red",GLUI_SPINNER_INT,&red_val);
    green_spinner = gluiWindow->add_spinner_to_panel(color_panel,"Green",GLUI_SPINNER_INT,&green_val);
    blue_spinner = gluiWindow->add_spinner_to_panel(color_panel,"Blue",GLUI_SPINNER_INT,&blue_val);
    red_spinner->set_int_limits(0,255,GLUI_LIMIT_WRAP);
    green_spinner->set_int_limits(0,255,GLUI_LIMIT_WRAP);
    blue_spinner->set_int_limits(0,255,GLUI_LIMIT_WRAP);

    clear_button = gluiWindow->add_button("Clear Screen",-1,clear_callback);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    halfHeight = glutGet(GLUT_WINDOW_HEIGHT)/2;
    halfWidth = glutGet(GLUT_WINDOW_WIDTH)/2;
    gluOrtho2D(-halfWidth, halfWidth, -halfHeight, halfHeight);

    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);

    glutDisplayFunc(display);
    glutMouseFunc(mouseCallback);
    glutMainLoop();
    return 0;
}