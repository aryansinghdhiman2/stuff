#include <GL/freeglut.h> // GLUT, includes glu.h and gl.h
// #include <GL/glui.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>

typedef std::bitset<4> pattern;

int halfHeight;
int halfWidth;
float red_val = 1,blue_val = 1,green_val = 1;
int thickness = 1;
pattern hex_pattern("1111");

struct pointPair {
    double x;
    double y;
    pointPair(double a,double b): x(a),y(b) {}
    pointPair(): x(0),y(0) {}
};

struct linePair {
    pointPair start;
    pointPair end;
    int number_of_points=0;
    linePair(pointPair a,pointPair b): start(a),end(b) {}
    linePair(pointPair a,pointPair b,int n): start(a),end(b),number_of_points(n) {}
    linePair(): start(pointPair()),end(pointPair()) {}
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

void simpleDDApattern(pointPair a,pointPair b)
{
    int pattern_pos = hex_pattern.size()-1;

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
        if(hex_pattern.test(pattern_pos))
        {
            glVertex2i(std::round(currentPos.x),std::round(currentPos.y));
        }
        pattern_pos--;
        if(pattern_pos == -1 ) pattern_pos = hex_pattern.size()-1;
    }
 
    glEnd();
    // glFlush();
}

void symmetericalDDAPattern(pointPair a,pointPair b)
{
    int pattern_pos = hex_pattern.size()-1;

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
        if(hex_pattern.test(pattern_pos))
        {
            glVertex2i(std::round(currentPos.x),std::round(currentPos.y));
        }
        pattern_pos--;
        if(pattern_pos == -1) pattern_pos = hex_pattern.size()-1;
    }
 
    glEnd();
    // glFlush();
}

void bresenhamPattern(pointPair a,pointPair b)
{
    int pattern_pos = hex_pattern.size()-1;

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

        if(hex_pattern.test(pattern_pos))
        {
            glVertex2i(currentPoint.x,currentPoint.y);
        }
        pattern_pos--;
        if(pattern_pos == -1) pattern_pos = hex_pattern.size()-1;
    }
    glEnd();
    // glFlush();

}

linePair parallelPointGenerator(pointPair a,pointPair b,float distance)
{
    double slope = (b.y-a.y)/(b.x-a.x);
    double angle = std::atan2(b.y-a.y,b.x-a.x);
    double offset_x = (double(distance)) * std::cos(angle + M_PI/2);
    double offset_y = (double(distance)) * std::sin(angle + M_PI/2);

    pointPair new_start = pointPair(a.x + offset_x,a.y + offset_y);
    pointPair new_end = pointPair(b.x + offset_x,b.y + offset_y);
    linePair newLine(new_start,new_end);
    return newLine;
}

void anotherMouseCallback(int button,int state,int x,int y)
{
    glColor3f(red_val,green_val,blue_val);
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
            // std::cout<<"Starting point: "<<lines.back().start.x<<' '<<lines.back().start.y<<' '<<lines.back().end.x<<' '<<lines.back().end.y<<std::endl;
            float i = -float(std::abs(thickness/2));
            while(std::trunc(i)<=float(std::abs(thickness/2)))
            {
                linePair newLine = parallelPointGenerator(lines.back().start,lines.back().end,i);
                // std::cout<<newLine.start.x<<" "<<newLine.start.y<<" "<<newLine.end.x<<' '<<newLine.end.y<<"\n";
                algorithmFunc(newLine.start,newLine.end);
                i+=0.1;
            }
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
        algorithmFunc = simpleDDApattern;
        break;
    case 1:
        algorithmFunc = symmetericalDDAPattern;
        break;
    case 2:
        algorithmFunc = bresenhamPattern;
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

void patternSelectorCallback(int choice)
{
    switch (choice)
    {
    case 0:
        hex_pattern = pattern("0101");
        break;
    case 1:
        hex_pattern = pattern("1001");
        break;
    case 2:
        hex_pattern = pattern("1111");
        break;
    default:
        break;
    }
}

void thicknessSelectorCallback(int choice)
{
    switch (choice)
    {
    case 0:
        thickness = 10;
        break;
    case 1:
        thickness = 5;
        break;
    case 2:
        thickness = 1;
        break;
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
    algorithmFunc = simpleDDApattern;

    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(250, 100);
    int main_window = glutCreateWindow("Simple DDA Mouse");

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

    int pattern_sub_menu = glutCreateMenu(patternSelectorCallback);
    glutAddMenuEntry("0101",0);
    glutAddMenuEntry("1001",1);
    glutAddMenuEntry("1111",2);

    int thickness_sub_menu = glutCreateMenu(thicknessSelectorCallback);
    glutAddMenuEntry("10",0);
    glutAddMenuEntry("5",1);
    glutAddMenuEntry("1",2);

    glutCreateMenu(menuCallback);
    glutAddSubMenu("Algorithm",algo_sub_menu);
    glutAddSubMenu("Color",color_sub_menu);
    glutAddSubMenu("Pattern",pattern_sub_menu);
    glutAddSubMenu("Thickness",thickness_sub_menu);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(display);
    glutMouseFunc(anotherMouseCallback);
    glutMainLoop();
    return 0;
}