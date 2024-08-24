#include <GL/freeglut.h> // GLUT, includes glu.h and gl.h
#include <iostream>
#include <cmath>
#include <vector>

int halfHeight;
int halfWidth;
float red_val = 1,blue_val = 1,green_val = 1;

struct pointPair {
    double x=0;
    double y=0;
};

struct linePair {
    pointPair start;
    pointPair end;
    int number_of_points=0;
};

std::vector<linePair> lines;

void (*algorithmFunc)(pointPair a,pointPair b);

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

void bresenham(pointPair a,pointPair b)
{
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
    glBegin(GL_POINTS);

        glVertex2i(a.x,a.y);
        glVertex2i(b.x,b.y);

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

        glVertex2i(currentPoint.x,currentPoint.y);
    }
    glEnd();
    glFlush();

}

void anotherMouseCallback(int button,int state,int x,int y)
{
    glColor3d(red_val,green_val,blue_val);
    int adjusted_x = x - halfWidth;
    int adjusted_y = -(y - halfHeight);
    if(button == GLUT_LEFT_BUTTON and state == GLUT_DOWN)
    {
        if(lines.empty() or lines.back().number_of_points==2)
        {
            pointPair point = {double(adjusted_x),double(adjusted_y)};
            linePair line;
            line.start = point;
            line.number_of_points=1;
            lines.push_back(line);
        }
        else 
        {
            lines.back().end = {double(adjusted_x),double(adjusted_y)};
            lines.back().number_of_points++;
        }
        if(lines.back().number_of_points == 2)
        {
            algorithmFunc(lines.back().start,lines.back().end);
        }
    }
    glFlush();
}

void menuCallback(int choice)
{

}

void algorithmSelectCallback(const int choice)
{
    switch (choice)
    {
    case 0:
        algorithmFunc = simpleDDA;
        break;
    case 1:
        algorithmFunc = symmetericalDDA;
        break;
    case 2:
        algorithmFunc = bresenham;
    default:
        break;
    }
}

void colorSelectCallback(int choice)
{
    switch (choice)
    {
    case 0:             //RED
        red_val = 1;
        green_val = 0;
        blue_val = 0;
        break;
    case 1:             //GREEN
        red_val = 0;
        green_val = 1;
        blue_val = 0;
        break;
    case 2:             //BLUE
        red_val = 0;
        green_val = 0;
        blue_val = 1;
        break;
    case 3:
        red_val = 1;
        green_val = 1;
        blue_val = 1;
    default:
        break;
    }
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
    glutCreateWindow("Simple DDA Mouse");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    halfHeight = glutGet(GLUT_WINDOW_HEIGHT)/2;
    halfWidth = glutGet(GLUT_WINDOW_WIDTH)/2;
    gluOrtho2D(-halfWidth, halfWidth, -halfHeight, halfHeight);

    int algo_sub_menu = glutCreateMenu(algorithmSelectCallback);
    glutAddMenuEntry("Simple DDA",0);
    glutAddMenuEntry("Symmetrical DDA",1);
    glutAddMenuEntry("Bresenham",2);

    int color_sub_menu = glutCreateMenu(colorSelectCallback);
    glutAddMenuEntry("Red",0);
    glutAddMenuEntry("Green",1);
    glutAddMenuEntry("Blue",2);
    glutAddMenuEntry("White",3);

    glutCreateMenu(menuCallback);
    glutAddSubMenu("Algorithm",algo_sub_menu);
    glutAddSubMenu("Color",color_sub_menu);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
    algorithmFunc = simpleDDA;

    glutDisplayFunc(display);
    // glutMouseFunc(mouseCallback);
    glutMouseFunc(anotherMouseCallback);
    glutMainLoop();
    return 0;
}