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
int red_val = 0,blue_val = 0,green_val = 0;
bool draw = false;
std::vector<linePair> polygon;
std::vector<pointPair> polygon_points;


GLUI_Listbox* algo_box;
GLUI_Rollout* color_rollout;
GLUI_Spinner* red_spinner;
GLUI_Spinner* blue_spinner;
GLUI_Spinner* green_spinner;
GLUI_Button* clear_button;

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

    glFlush();

    return points;
}

void boundaryFillStack4(pointPair currentPoint,color boundary_color,color fill_color)
{
    std::stack<pointPair> my_stack;
    currentPoint.x = int(currentPoint.x);
    currentPoint.y = int(currentPoint.y);
    my_stack.push(currentPoint);
    float colors[3];
    while(not my_stack.empty()){
        pointPair point = my_stack.top();
        my_stack.pop();
        glReadPixels(point.x+halfWidth,point.y+halfHeight,1,1,GL_RGB,GL_FLOAT,colors);
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

void boundaryFillStack8(pointPair currentPoint,color boundary_color,color fill_color)
{
    std::stack<pointPair> my_stack;
    currentPoint.x = int(currentPoint.x);
    currentPoint.y = int(currentPoint.y);
    my_stack.push(currentPoint);
    float colors[3];
    while(not my_stack.empty()){
        pointPair point = my_stack.top();
        my_stack.pop();
        glReadPixels(point.x+halfWidth,point.y+halfHeight,1,1,GL_RGB,GL_FLOAT,colors);
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
            my_stack.push({point.x+1,point.y+1});
            my_stack.push({point.x+1,point.y-1});
            my_stack.push({point.x-1,point.y+1});
            my_stack.push({point.x-1,point.y-1});
        }
    }
}

void floodFillStack4(pointPair currentPoint,color old_color,color fill_color)
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
        glReadPixels(point.x+halfWidth,point.y+halfHeight,1,1,GL_RGB,GL_FLOAT,colors);

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

void floodFillStack8(pointPair currentPoint,color old_color,color fill_color)
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
        glReadPixels(point.x+halfWidth,point.y+halfHeight,1,1,GL_RGB,GL_FLOAT,colors);

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
            my_stack.push({point.x+1,point.y+1});
            my_stack.push({point.x+1,point.y-1});
            my_stack.push({point.x-1,point.y+1});
            my_stack.push({point.x-1,point.y-1});
        }
    }
}

void scanLinePolygon(const std::vector<linePair>& polygon,const std::vector<pointPair>& points,const color& fill_color)
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
        pointPair row_start = scan_start_point;
        bool row_started_at_beginning = false;
        bool row_started_at_end = false;

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
                    pointPair next_point = {scan_point.x+1,scan_point.y};
                    auto find_next_point = [next_point](const pointPair a){
                                if(a.x==next_point.x and a.y==next_point.y)
                                    return true;
                                else return false;
                            };

                    bool around_edge = false;

                    if(polygon_point_itr+3 != points.end())
                    {
                        around_edge = (abs(polygon_point_itr->x - (polygon_point_itr+3)->x) == 1) ? true : false;
                    }

                    if((row_started_at_beginning or row_started_at_end) and std::find_if(points.begin(),points.end(),find_next_point) == points.end())
                    {
                        if(row_started_at_beginning)
                        {
                            row_started_at_beginning = false;
                            intersection_pair.end = scan_point;
                            intersection_start_found = false;
                            bresenham(intersection_pair.start,intersection_pair.end,fill_color);
                            intersection_start_found = true;
                            intersection_pair.start = scan_point;
                        }
                        else if(row_started_at_end)
                        {
                            row_started_at_end = false;
                            intersection_pair.end = scan_point;
                            intersection_start_found = false;
                            bresenham(intersection_pair.start,intersection_pair.end,fill_color);
                            // intersection_start_found = true;
                            // intersection_pair.start = scan_point;
                        }
                    }
                    else if(scan_point.x-1==intersection_pair.start.x)
                    {
                        if(std::find_if(points.begin(),points.end(),find_next_point) == points.end())
                        {
                            intersection_pair.end = scan_point;
                            intersection_start_found = false;
                            bresenham(intersection_pair.start,intersection_pair.end,fill_color);
                            auto previous_point = *(polygon_point_itr-1);
                            auto edge_point_itr = std::find_if(polygon.begin(),
                                               polygon.end(),
                                               [previous_point](const linePair a){
                                                    if(a.start.x==previous_point.x and a.start.y==previous_point.y)
                                                      return true;
                                                    else return false;
                                                });

                            if(edge_point_itr == polygon.end())
                            {
                                intersection_start_found = true;
                                intersection_pair.start = scan_point;
                            }
                        }
                        else
                        {
                            row_start = {scan_point.x-1,scan_point.y};
                            row_started_at_beginning = true;
                        }
                    }
                    else if(std::find_if(points.begin(),points.end(),find_next_point) != points.end() and not around_edge)
                    {
                        row_started_at_end = true;
                    }
                    else if(not row_started_at_beginning and not row_started_at_end)
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
                pointPair previous_point;
                if(edge_point_itr == polygon.begin())
                {
                    previous_point = *(points.end()-2);
                }
                else
                {
                    previous_point = *(polygon_point_itr - 2);
                }
                pointPair next_point = *(polygon_point_itr+2);

                int previous_delta_y = polygon_point_itr->y - previous_point.y;
                int next_delta_y = next_point.y - polygon_point_itr->y;
                bool shorten_edge = false;
                
                if(next_delta_y!=0 and previous_delta_y!=0)
                {
                    shorten_edge = ((float)next_delta_y / (float)previous_delta_y > 0) ? true : false;
                }
                else if(next_delta_y==0 or previous_delta_y==0)
                {
                    shorten_edge = true;
                }
                
                if(not shorten_edge)
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
    static color boundary_color;
    static color fill_color;

    if(button == GLUT_LEFT_BUTTON and state == GLUT_DOWN)
    {
        if(not draw)
        {
            draw = true;
            previousPoint = {adjusted_x,adjusted_y};
        }
        else 
        {
            boundary_color.at(0) = red_spinner->get_float_val()/255.0;
            boundary_color.at(1) = green_spinner->get_float_val()/255.0;
            boundary_color.at(2) = blue_spinner->get_float_val()/255.0;
            linePair line = {previousPoint,{adjusted_x,adjusted_y}};
            auto points = bresenham(line.start,line.end,boundary_color);
            polygon.push_back(line);
            polygon_points.insert(polygon_points.end(),points.begin(),points.end());
        }
        previousPoint = {adjusted_x,adjusted_y};
    }
    else if(button == GLUT_MIDDLE_BUTTON and state == GLUT_DOWN and draw and polygon.size() > 1)
    {
        boundary_color.at(0) = red_spinner->get_float_val()/255.0;
        boundary_color.at(1) = green_spinner->get_float_val()/255.0;
        boundary_color.at(2) = blue_spinner->get_float_val()/255.0;

        auto points = bresenham(polygon.back().end,polygon.front().start,boundary_color);
        polygon.push_back({polygon.back().end,polygon.front().start});
        polygon_points.insert(polygon_points.end(),points.begin(),points.end());
    }
    else if(button == GLUT_RIGHT_BUTTON and state == GLUT_DOWN and draw and polygon.size() > 2)
    {
        fill_color.at(0) = red_spinner->get_float_val()/255.0;
        fill_color.at(1) = green_spinner->get_float_val()/255.0;
        fill_color.at(2) = blue_spinner->get_float_val()/255.0;

        int control = algo_box->get_int_val();
        color old_color;
        switch (control)
        {
        case 0:
            scanLinePolygon(polygon,polygon_points,fill_color);
            break;
        case 1:
            boundaryFillStack4({adjusted_x,adjusted_y},boundary_color,fill_color);
            break;
        case 2:
            
            glReadPixels(adjusted_x+halfWidth,adjusted_y+halfWidth,1,1,GL_RGB,GL_FLOAT,old_color.data());
            floodFillStack4({adjusted_x,adjusted_y},old_color,fill_color);
            break;
        // case 3:
        //     boundaryFillStack8({adjusted_x,adjusted_y},boundary_color,fill_color);
        //     break;
        // case 4:
        //     glReadPixels(adjusted_x+halfWidth,adjusted_y+halfWidth,1,1,GL_RGB,GL_FLOAT,old_color.data());
        //     floodFillStack8({adjusted_x,adjusted_y},old_color,fill_color);
        //     break;
        default:
            break;
        }

        polygon.clear();
        polygon_points.clear();
        draw = false;
    }
    glFlush();
}

void clear_callback(const int i)
{
    // glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    polygon.clear();
    polygon_points.clear();
    draw = false;
    glutPostRedisplay();
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

    algo_box = gluiWindow->add_listbox("Filling Algorithm");
    algo_box->add_item(0,"Scan Line");
    algo_box->add_item(1,"Boundary Fill");
    algo_box->add_item(2,"Flood Fill");
    // algo_box->add_item(3,"Boundary Fill 8");
    // algo_box->add_item(4,"Flood Fill 8");

    gluiWindow->add_column(1);

    color_rollout = gluiWindow->add_rollout("Color",0);
    color_rollout->set_w(163);
    red_spinner = gluiWindow->add_spinner_to_panel(color_rollout,"Red",GLUI_SPINNER_INT,&red_val);
    blue_spinner = gluiWindow->add_spinner_to_panel(color_rollout,"Blue",GLUI_SPINNER_INT,&blue_val);
    green_spinner = gluiWindow->add_spinner_to_panel(color_rollout,"Green",GLUI_SPINNER_INT,&green_val);
    red_spinner->set_int_limits(0,255,GLUI_LIMIT_WRAP);
    blue_spinner->set_int_limits(0,255,GLUI_LIMIT_WRAP);
    green_spinner->set_int_limits(0,255,GLUI_LIMIT_WRAP);

    gluiWindow->add_column();

    clear_button = gluiWindow->add_button("Clear",-1,clear_callback);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    halfHeight = glutGet(GLUT_WINDOW_HEIGHT)/2;
    halfWidth = glutGet(GLUT_WINDOW_WIDTH)/2;
    gluOrtho2D(-halfWidth, halfWidth, -halfHeight, halfHeight);
    // glClearColor(1,1,1,1);
    // glClear(GL_COLOR_BUFFER_BIT);
    glutMainLoop();
    return 0;
}