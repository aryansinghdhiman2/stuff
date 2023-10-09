#include <GL/freeglut.h> // GLUT, includes glu.h and gl.h
#include <GL/glui.h>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <stack>
#include <array>
#include <algorithm>

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

std::vector<pointPair> simpleDDA(pointPair a,pointPair b,const color& fill_color)
{
    std::vector<pointPair> points;

    float delta_x = b.x-a.x;
    float delta_y = b.y-a.y;

    int line_length_estimate = (std::max(abs(delta_x),abs(delta_y)));
    float epsilon = 1 / float(line_length_estimate);
    float x_increment = epsilon * delta_x;
    float y_increment = epsilon * delta_y;
    pointPair currentPos = a;
    glPointSize(1);
    glRasterPos2i(std::round(currentPos.x),std::round(currentPos.y));
    glDrawPixels(1,1,GL_RGB,GL_FLOAT,fill_color.data());
    points.push_back({std::round(a.x),std::round(a.y)});
    for(int i = 1; i<line_length_estimate;i++)
    {
        currentPos.x += x_increment;
        currentPos.y += y_increment;
        {
            glRasterPos2i(std::round(currentPos.x),std::round(currentPos.y));
            glDrawPixels(1,1,GL_RGB,GL_FLOAT,fill_color.data());
            points.push_back({std::round(currentPos.x),std::round(currentPos.y)});
        }
    }
 
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
        if(scan_point.y == 119)
        {
            std::cout<<"Here";
        }
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
                            simpleDDA(intersection_pair.start,intersection_pair.end,fill_color);
                            // intersection_start_found = true;
                            // intersection_pair.start = scan_point;
                        }
                        else if(row_started_at_end)
                        {
                            row_started_at_end = false;
                            intersection_pair.end = scan_point;
                            intersection_start_found = false;
                            simpleDDA(intersection_pair.start,intersection_pair.end,fill_color);
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
                            simpleDDA(intersection_pair.start,intersection_pair.end,fill_color);
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
                        simpleDDA(intersection_pair.start,intersection_pair.end,fill_color);
                    }
                }
                else
                {
                    intersection_pair.start = scan_point;
                    intersection_start_found = true;
                }
            }
            // else if(scan_point.y == 119)
            // {
            //     glRasterPos2i(scan_point.x,scan_point.y);
            //     float green[3] = {0,1,0};
            //     glDrawPixels(1,1,GL_RGB,GL_FLOAT,green);
            //     glFlush();
            // }

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
                        simpleDDA(intersection_pair.start,intersection_pair.end,fill_color);
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
// std::vector<pointPair> polygon_points;
// std::vector<linePair> newpoly;
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
            previousPoint = {(double)adjusted_x,(double)adjusted_y};
        }
        else 
        {
            linePair line = {previousPoint,{(double)adjusted_x,(double)adjusted_y}};
            auto points = simpleDDA(line.start,line.end,{1,1,1});
            polygon.push_back(line);
            polygon_points.insert(polygon_points.end(),points.begin(),points.end());
        }
        previousPoint = {(double)adjusted_x,(double)adjusted_y};
        std::cout<<adjusted_x<<','<<adjusted_y<<std::endl;
        // simpleDDA(currentPos,{double(adjusted_x),double(adjusted_y)});
        // boundaryFillStack({double(adjusted_x),double(adjusted_y)},{1,1,1});
        // floodFillStack({double(adjusted_x),double(adjusted_y)},{0,0,0},{(float)red_val/(float)255.0,(float)green_val/(float)255.0,(float)blue_val/(float)255.0});
    }
    else if(button == GLUT_MIDDLE_BUTTON and state == GLUT_DOWN and draw and polygon.size() > 1)
    {
        auto points = simpleDDA(polygon.back().end,polygon.front().start,{1,1,1});
        polygon.push_back({polygon.back().end,polygon.front().start});
        polygon_points.insert(polygon_points.end(),points.begin(),points.end());
    }
    else if(button == GLUT_RIGHT_BUTTON and state == GLUT_DOWN)
    {
        // std::vector<linePair> npoly;
        // std::vector<pointPair> pts;
        // npoly.push_back({{-120,-81},{-137,5}});
        // npoly.push_back({{-137,5},{-210,120}});
        // npoly.push_back({{-210,120},{-89,70}});
        // npoly.push_back({{-89,70},{-4,135}});
        // npoly.push_back({{-4,135},{-4,-43}});
        // npoly.push_back({{-4,-43},{-120,-81}});

        // auto v1 = simpleDDA({-120,-81},{-137,5},{1.0,0.0,0.0});
        // auto v2 = simpleDDA({-137,5},{-210,120},{1.0,0.0,0.0});
        // auto v3 = simpleDDA({-210,120},{-89,70},{1.0,0.0,0.0});
        // auto v4 = simpleDDA({-89,70},{-4,135},{1.0,0.0,0.0});
        // auto v5 = simpleDDA({-4,135},{-4,-43},{1.0,0.0,0.0});
        // auto v6 = simpleDDA({-4,-43},{-120,-81},{1.0,0.0,0.0});

        // pts.insert(pts.end(),v1.begin(),v1.end());
        // pts.insert(pts.end(),v2.begin(),v2.end());
        // pts.insert(pts.end(),v3.begin(),v3.end());
        // pts.insert(pts.end(),v4.begin(),v4.end());
        // pts.insert(pts.end(),v5.begin(),v5.end());
        // pts.insert(pts.end(),v6.begin(),v6.end());

        scanLinePolygon(polygon,polygon_points,{1.0,1.0,1.0},{1.0,0.0,0.0});
    }
    glFlush();
}

void display()
{
    // simpleDDA({0,0},{0,20},{1,1,1});
    // simpleDDA({0,20},{30,30},{1,1,1});
    // simpleDDA({30,30},{30,0},{1,1,1});
    // simpleDDA({30,0},{0,0},{1,1,1});
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(-1, -1);
    int main_window = glutCreateWindow("Filling");

        // auto v1 = simpleDDA({0,0},{0,20},{1,1,1});
        // auto v2 = simpleDDA({0,20},{30,30},{1,1,1});
        // auto v3 = simpleDDA({30,30},{30,0},{1,1,1});
        // auto v4 = simpleDDA({30,0},{0,0},{1,1,1});
        // polygon_points.insert(polygon_points.begin(),v1.begin(),v1.end());
        // polygon_points.insert(polygon_points.begin(),v2.begin(),v2.end());
        // polygon_points.insert(polygon_points.begin(),v3.begin(),v3.end());
        // polygon_points.insert(polygon_points.begin(),v4.begin(),v4.end());
        // newpoly.push_back({{0,0},{0,20}});
        // newpoly.push_back({{0,20},{30,30}});
        // newpoly.push_back({{30,30},{30,0}});
        // newpoly.push_back({{30,0},{0,0}});
    // GLUI_Master.set_glutIdleFunc(nullptr);
    // GLUI_Master.set_glutMouseFunc(mouseCallback);
    // GLUI_Master.set_glutDisplayFunc(display);
    // GLUI *gluiWindow = GLUI_Master.create_glui_subwindow(main_window,GLUI_SUBWINDOW_TOP);
    // gluiWindow->set_main_gfx_window(main_window);

    // shape_box = gluiWindow->add_listbox("Shape",nullptr,-1);
    // shape_box->add_item(0,"Square");
    // shape_box->add_item(1,"Circle");
    // shape_box->add_item(2,"Ellipse");
    // shape_box->add_item(3,"Triangle");

    // color_rollout = gluiWindow->add_rollout("Color",0);
    // color_rollout->set_w(163);
    // red_spinner = gluiWindow->add_spinner_to_panel(color_rollout,"Red",GLUI_SPINNER_INT,&red_val);
    // blue_spinner = gluiWindow->add_spinner_to_panel(color_rollout,"Blue",GLUI_SPINNER_INT,&blue_val);
    // green_spinner = gluiWindow->add_spinner_to_panel(color_rollout,"Green",GLUI_SPINNER_INT,&green_val);
    // red_spinner->set_int_limits(0,255,GLUI_LIMIT_WRAP);
    // blue_spinner->set_int_limits(0,255,GLUI_LIMIT_WRAP);
    // green_spinner->set_int_limits(0,255,GLUI_LIMIT_WRAP);

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