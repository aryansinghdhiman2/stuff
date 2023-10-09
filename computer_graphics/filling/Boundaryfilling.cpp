#include <GL/freeglut.h> // GLUT, includes glu.h and gl.h
#include <GL/glui.h>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <stack>
#include <array>

int halfHeight;
int halfWidth;
int red_val = 255,blue_val = 255,green_val = 255;

struct pointPair {
    double x;
    double y;
};

typedef std::array<float,3> color;

GLUI_Listbox* shape_box;
GLUI_Rollout* color_rollout;
GLUI_Spinner* red_spinner;
GLUI_Spinner* blue_spinner;
GLUI_Spinner* green_spinner;

void drawAxes()
{
    glLineWidth(2.0f);
    glColor3d(1.0f,1.0f,1.0f);
    glBegin(GL_LINES);
        glVertex2i(halfWidth,0);
        glVertex2i(-halfWidth,0);
        glVertex2i(0,halfHeight);
        glVertex2i(0,-halfHeight);

        glVertex2i(halfWidth,halfHeight);
        glVertex2i(halfWidth,-halfHeight);
        glVertex2i(halfWidth,-halfHeight);
        glVertex2i(-halfWidth,-halfHeight);
        glVertex2i(-halfWidth,-halfHeight);
        glVertex2i(-halfWidth,halfHeight);
        glVertex2i(-halfWidth,halfHeight);
        glVertex2i(halfWidth,halfHeight);
    glEnd();
}

void boundaryFillStack(pointPair currentPoint,color boundary_color,color fill_color)
{
    std::stack<pointPair> my_stack;
    currentPoint.x = int(currentPoint.x);
    currentPoint.y = int(currentPoint.y);
    my_stack.push(currentPoint);
    float colors[3];
    while(not my_stack.empty()){
        pointPair point = my_stack.top();
        my_stack.pop();
        glReadPixels(point.x+halfWidth,point.y+halfHeight,1,1,GL_RGB,GL_FLOAT,&colors);
        if(
            (colors[0]!=boundary_color.at(0) and colors[1]!=boundary_color.at(1) and colors[2]!=boundary_color.at(2))
            or
            (colors[0]!=fill_color.at(0) and colors[1]!=fill_color.at(1) and colors[2]!=fill_color.at(2))
        )
        {
            glPointSize(1);
            glColor3f(1,0,0);
            glRasterPos2i(point.x,point.y);
            glDrawPixels(1,1,GL_RGB,GL_FLOAT,fill_color.data());
            glFlush();
            my_stack.push({point.x,point.y-1});
            my_stack.push({point.x,point.y+1});
            my_stack.push({point.x-1,point.y});
            my_stack.push({point.x+1,point.y});
        }
    }
}

void floodFillStack(pointPair currentPoint,color old_color,color fill_color)
{
    std::stack<pointPair> my_stack;
    currentPoint.x = int(currentPoint.x);
    currentPoint.y = int(currentPoint.y);
    my_stack.push(currentPoint);
    float colors[3];

    while(not my_stack.empty())
    {
        pointPair point = my_stack.top();
        my_stack.pop();
        glReadPixels(point.x+halfWidth,point.y+halfHeight,1,1,GL_RGB,GL_FLOAT,&colors);

        if(colors[0]==old_color.at(0) and colors[1]==old_color.at(1) and colors[2]==old_color.at(2))
        {
            glPointSize(1);
            glColor3f(1,0,0);
            glRasterPos2i(point.x,point.y);
            glDrawPixels(1,1,GL_RGB,GL_FLOAT,fill_color.data());
            glFlush();
            my_stack.push({point.x,point.y-1});
            my_stack.push({point.x,point.y+1});
            my_stack.push({point.x-1,point.y});
            my_stack.push({point.x+1,point.y});
        }
    }
}

void mouseCallback(int button,int state,int x,int y)
{
    glColor3d(1.0f,1.0f,1.0f);
    int adjusted_x = x - halfWidth;
    int adjusted_y = -(y - halfHeight);
    if(button == GLUT_RIGHT_BUTTON and state == GLUT_DOWN)
    {
        // simpleDDA(currentPos,{double(adjusted_x),double(adjusted_y)});
        // boundaryFillStack({double(adjusted_x),double(adjusted_y)},{1,1,1});
        floodFillStack({double(adjusted_x),double(adjusted_y)},{0,0,0},{(float)red_val/(float)255.0,(float)green_val/(float)255.0,(float)blue_val/(float)255.0});
    }
    glFlush();
}

void display()
{
    drawAxes();
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2d(0,0);
    glVertex2d(100,0);
    glVertex2d(100,0);
    glVertex2d(100,100);
    glVertex2d(100,100);
    glVertex2d(0,100);
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(-1, -1);
    int main_window = glutCreateWindow("Simple DDA Mouse");

    GLUI_Master.set_glutIdleFunc(nullptr);
    GLUI_Master.set_glutMouseFunc(mouseCallback);
    GLUI_Master.set_glutDisplayFunc(display);
    GLUI *gluiWindow = GLUI_Master.create_glui_subwindow(main_window,GLUI_SUBWINDOW_TOP);
    gluiWindow->set_main_gfx_window(main_window);

    shape_box = gluiWindow->add_listbox("Shape",nullptr,-1);
    shape_box->add_item(0,"Square");
    shape_box->add_item(1,"Circle");
    shape_box->add_item(2,"Ellipse");
    shape_box->add_item(3,"Triangle");

    color_rollout = gluiWindow->add_rollout("Color",0);
    color_rollout->set_w(163);
    red_spinner = gluiWindow->add_spinner_to_panel(color_rollout,"Red",GLUI_SPINNER_INT,&red_val);
    blue_spinner = gluiWindow->add_spinner_to_panel(color_rollout,"Blue",GLUI_SPINNER_INT,&blue_val);
    green_spinner = gluiWindow->add_spinner_to_panel(color_rollout,"Green",GLUI_SPINNER_INT,&green_val);
    red_spinner->set_int_limits(0,255,GLUI_LIMIT_WRAP);
    blue_spinner->set_int_limits(0,255,GLUI_LIMIT_WRAP);
    green_spinner->set_int_limits(0,255,GLUI_LIMIT_WRAP);

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