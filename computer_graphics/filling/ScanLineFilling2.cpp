#include <GL/freeglut.h> // GLUT, includes glu.h and gl.h
#include <GL/glui.h>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <stack>
#include <array>
#include <algorithm>

struct pointPair {
    int x;
    int y;
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

GLUI_Listbox* shape_box;
GLUI_Rollout* color_rollout;
GLUI_Spinner* red_spinner;
GLUI_Spinner* blue_spinner;
GLUI_Spinner* green_spinner;

void drawLine(const pointPair& start,const pointPair& end)
{
    glBegin(GL_LINES);
    glVertex2i(start.x,start.y);
    glVertex2i(end.x,end.y);
    glEnd();
    glFlush();
}

void drawLine(const pointPair& start,const pointPair& end,const color& fill_color)
{
    glColor3f(fill_color.at(0),fill_color.at(1),fill_color.at(2));
    glBegin(GL_LINES);
    glVertex2i(start.x,start.y);
    glVertex2i(end.x,end.y);
    glEnd();
    glFlush();
}

std::vector<pointPair> bresenham(pointPair a,pointPair b,color fill_color)
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
    glRasterPos2i((int)currentPoint.x,(int)currentPoint.y);
    glDrawPixels(1,1,GL_RGB,GL_FLOAT,fill_color.data());

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

        points.push_back(currentPoint);
        glRasterPos2i((int)currentPoint.x,(int)currentPoint.y);
        glDrawPixels(1,1,GL_RGB,GL_FLOAT,fill_color.data());
    }

    points.push_back(b);
    glRasterPos2i(b.x,b.y);
    glDrawPixels(1,1,GL_RGB,GL_FLOAT,fill_color.data());
    glFlush();

    return points;
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

void scanLinePolygon(const std::vector<linePair>& polygon,const std::vector<pointPair>& points,const color& polygon_color,const color& fill_color)
{
    pointPair top_most;
    pointPair right_most;
    pointPair left_most;
    pointPair bottom_most;

    auto top_most_itr = std::max_element(polygon.begin(),
                                         polygon.end(),
                                         [](const linePair a,const linePair b){
                                             if(a.start.y < b.start.y) return true;
                                             else return false;
                                         }
    );
    top_most = top_most_itr->start;

    auto right_most_itr = std::max_element(polygon.begin(),
                                           polygon.end(),
                                           [](const linePair a,const linePair b){
                                               if(a.start.x < b.start.x) return true;
                                               else return false;
                                           }
    );
    right_most = right_most_itr->start;

    auto left_most_itr = std::min_element(polygon.begin(),
                                          polygon.end(),
                                          [](const linePair a,const linePair b){
                                              if(a.start.x < b.start.x) return true;
                                              else return false;
                                          }
    );
    left_most = left_most_itr->start;

    auto bottom_most_itr = std::min_element(polygon.begin(),
                                            polygon.end(),
                                            [](const linePair a,const linePair b){
                                                if(a.start.y < b.start.y) return true;
                                                else return false;
                                            }
    );
    bottom_most = bottom_most_itr->start;

    pointPair scan_start_point = {left_most.x,bottom_most.y};
    std::vector<linePair> intersections;

    while(scan_start_point.y <= top_most.y)
    {
        pointPair scan_point = scan_start_point;
        linePair intersection_pair;
        bool intersection_start_found = false;

        while(scan_point.x <= right_most.x)
        {
            auto polygon_point_itr = std::find_if(points.begin(),
                                                  points.end(),
                                                  [scan_point](const pointPair a){
                                                      if(a.x==scan_point.x and a.y==scan_point.y)
                                                          return true;
                                                      else return false;
                                                    });
            if(polygon_point_itr != points.end())
            {
                if(intersection_start_found)
                {
                    if(scan_point.x-1==intersection_pair.start.x)
                    {
                        pointPair next_point = {scan_point.x+1,scan_point.y};
                        auto find_next_point = [next_point](const pointPair a){
                                                if(a.x==next_point.x and a.y==next_point.y)
                                                    return true;
                                                else return false;
                                            };
                        if(std::find_if(points.begin(),points.end(),find_next_point) == points.end())
                        {
                            intersection_pair.end = scan_point;
                            intersection_start_found = false;
                            bresenham(intersection_pair.start,intersection_pair.end,fill_color);
                            intersection_start_found = true;
                            intersection_pair.start = scan_point;
                        }
                    }
                    else
                    {
                        intersection_pair.end = scan_point;
                        intersection_start_found = false;
                        bresenham(intersection_pair.start,intersection_pair.end,fill_color);
                    }
                }
                else
                {
                    intersection_pair.start = scan_point;
                    intersection_start_found = true;
                }
            }

            auto edge_point_itr = std::find_if(polygon.begin(),
                                               polygon.end(),
                                               [scan_point](const linePair a){
                                                    if(a.start.x==scan_point.x and a.start.y==scan_point.y)
                                                      return true;
                                                    else return false;
                                                });

            if(edge_point_itr!=polygon.end())
            {
                if(intersection_start_found)
                {
                    intersection_pair.end = scan_point;
                    intersection_start_found = false;
                    bresenham(intersection_pair.start,intersection_pair.end,fill_color);
                }
                else
                {
                    intersection_pair.start = scan_point;
                    intersection_start_found = true;
                }
            }
            scan_point.x+=1;
        }
        scan_start_point.y+=1;
    }
    glFlush();
}
void mouseCallback(int button,int state,int x,int y)
{
    glColor3d(1.0f,1.0f,1.0f);
    int adjusted_x = x - halfWidth;
    int adjusted_y = -(y - halfHeight);
    static pointPair previousPoint;
    static std::vector<linePair> polygon;
    static std::vector<pointPair> polygon_points;

    if(button == GLUT_LEFT_BUTTON and state == GLUT_DOWN)
    {
        if(not draw)
        {
            draw = true;
            previousPoint = {adjusted_x,adjusted_y};
        }
        else 
        {
            linePair line = {previousPoint,{adjusted_x,adjusted_y}};
            auto points = bresenham(line.start,line.end,{1,1,1});
            polygon.push_back(line);
            polygon_points.insert(polygon_points.begin(),points.begin(),points.end());
        }
        previousPoint = {adjusted_x,adjusted_y};
        // simpleDDA(currentPos,{double(adjusted_x),double(adjusted_y)});
        // boundaryFillStack({double(adjusted_x),double(adjusted_y)},{1,1,1});
        // floodFillStack({double(adjusted_x),double(adjusted_y)},{0,0,0},{(float)red_val/(float)255.0,(float)green_val/(float)255.0,(float)blue_val/(float)255.0});
    }
    else if(button == GLUT_MIDDLE_BUTTON and state == GLUT_DOWN and draw and polygon.size() > 1)
    {
        auto points = bresenham(polygon.back().end,polygon.front().start,{1,1,1});
        polygon.push_back({polygon.back().end,polygon.front().start});
        polygon_points.insert(polygon_points.begin(),points.begin(),points.end());
    }
    else if(button == GLUT_RIGHT_BUTTON and state == GLUT_DOWN)
    {
        scanLinePolygon(polygon,polygon_points,{1.0,1.0,1.0},{1.0,0.0,0.0});
    }
    glFlush();
}

void display()
{
    // bresenham({0,0},{0,20},{1,1,1});
    // bresenham({0,20},{30,30},{1,1,1});
    // bresenham({30,30},{30,0},{1,1,1});
    // bresenham({30,0},{0,0},{1,1,1});
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(-1, -1);
    int main_window = glutCreateWindow("Filling");

    // auto v1 = bresenham({0,0},{0,20},{1,1,1});
    // auto v2 = bresenham({0,20},{30,30},{1,1,1});
    // auto v3 = bresenham({30,30},{30,0},{1,1,1});
    // auto v4 = bresenham({30,0},{0,0},{1,1,1});
    // polygon_points.insert(polygon_points.begin(),v1.begin(),v1.end());
    // polygon_points.insert(polygon_points.begin(),v2.begin(),v2.end());
    // polygon_points.insert(polygon_points.begin(),v3.begin(),v3.end());
    // polygon_points.insert(polygon_points.begin(),v4.begin(),v4.end());
    // newpoly.push_back({{0,0},{0,20}});
    // newpoly.push_back({{0,20},{30,30}});
    // newpoly.push_back({{30,30},{30,0}});
    // newpoly.push_back({{30,0},{0,0}});
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