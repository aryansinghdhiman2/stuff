#include <GL/freeglut.h> // GLUT, includes glu.h and gl.h
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <bitset>
#include <GL/glui.h>
#include "../csvHandler.hpp"
#include "./ellipse_helper.hpp"

typedef std::bitset<4> pattern;
pattern hex_pattern("1111");
int red_val = 255,blue_val = 255,green_val = 255;
int halfHeight;
int halfWidth;
int ignore_counter = 0;
GLUI_EditText* pattern_box;
GLUI_Rollout* color_rollout;
GLUI_Spinner* red_spinner;
GLUI_Spinner* blue_spinner;
GLUI_Spinner* green_spinner;
GLUI_Button* undo_button;
GLUI_Button* redo_button;
GLUI_Button* clear_screen_button;

CSVHandler handler("../ellipse.csv");

inline void drawAxes();
inline void drawGuidelines(const pointPair center);
inline void ShiftAndDrawPoint(pointPair originalPoint,pointPair shiftBy);
inline void drawEllipsePoint(const pointPair& currentPoint,const pointPair center);
void midpointEllipseDrawingAlgorithm(const pointPair center,float radius_x,float radius_y);
void redrawScreenFromFile();
void mouseCallback(int button,int state,int x,int y);
void patternConverter(std::string input_pattern);
void patternSelectorCallback(const int id);
void clearScreen();
void clearScreenCallback(int id);
void undoCallback(const int id);
void redoCallback(const int id);
void display();


inline void drawAxes()
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

inline void drawGuidelines(const pointPair center)
{
    glColor3d(red_val/255.0,green_val/255.0,blue_val/255.0);
    glBegin(GL_LINES);
        glVertex2i(halfWidth,center.y);
        glVertex2i(-halfWidth,center.y);
        glVertex2i(center.x,halfHeight);
        glVertex2i(center.x,-halfHeight);
    glEnd();
}

inline void ShiftAndDrawPoint(pointPair originalPoint,pointPair shiftBy)
{
    glBegin(GL_POINTS);
    glVertex2d(originalPoint.x+shiftBy.x,originalPoint.y+shiftBy.y);
    glEnd();
}

inline void drawEllipsePoint(const pointPair& currentPoint,const pointPair center)
{
    glBegin(GL_POINTS);
    ShiftAndDrawPoint({currentPoint.x,currentPoint.y},center);
    ShiftAndDrawPoint({currentPoint.x,-currentPoint.y},center);
    ShiftAndDrawPoint({-currentPoint.x,-currentPoint.y},center);
    ShiftAndDrawPoint({-currentPoint.x,currentPoint.y},center);
    glEnd();
}

void midpointEllipseDrawingAlgorithm(const pointPair center,float radius_x,float radius_y)
{
    int pattern_pos = hex_pattern.size()-1;

    float pk = std::pow(radius_y,2)-std::pow(radius_x,2)*radius_y+std::pow(radius_x,2)/4.0;
    pointPair currentPoint = {0,radius_y};
    
    if(hex_pattern.test(pattern_pos))
    {
        drawEllipsePoint(currentPoint,center);
    }
    
    while(2*std::pow(radius_y,2)*currentPoint.x < 2*std::pow(radius_x,2)*currentPoint.y)
    {
        if(pk < 0)
        {
            currentPoint.x = currentPoint.x + 1;
            pk = pk + 2*std::pow(radius_y,2)*currentPoint.x + std::pow(radius_y,2);
        }
        else
        {
            currentPoint.x = currentPoint.x + 1;
            currentPoint.y = currentPoint.y - 1;
            pk = pk + 2*std::pow(radius_y,2)*currentPoint.x + std::pow(radius_y,2) - 2*std::pow(radius_x,2)*currentPoint.y;
        }
        if(hex_pattern.test(pattern_pos))
        {
            drawEllipsePoint(currentPoint,center);
        }
        pattern_pos--;
        if(pattern_pos == -1 ) pattern_pos = hex_pattern.size()-1;
    }

    pk = std::pow(radius_y,2)*std::pow(radius_x+0.5,2) + std::pow(radius_x,2)*std::pow(radius_y-1,2)-std::pow(radius_x,2)*std::pow(radius_y,2);

    while(currentPoint.y > 0)
    {
        if(pk < 0)
        {
            currentPoint.x = currentPoint.x + 1;
            currentPoint.y = currentPoint.y - 1;
            pk = pk + 2*std::pow(radius_y,2)*currentPoint.x + std::pow(radius_x,2) - 2*std::pow(radius_x,2)*currentPoint.y;
        }
        else
        {
            currentPoint.x = currentPoint.x + 1;
            currentPoint.y = currentPoint.y - 1;
            pk = pk - 2*std::pow(radius_x,2)*currentPoint.y + std::pow(radius_x,2);
        }
        if(hex_pattern.test(pattern_pos))
        {
            drawEllipsePoint(currentPoint,center);
        }
        pattern_pos--;
        if(pattern_pos == -1 ) pattern_pos = hex_pattern.size()-1;
    }
    // glFlush();
       
}

void redrawScreenFromFile()
{
    clearScreen();
    auto ellipses = readFile(handler,ignore_counter);
    for(auto ellipse : ellipses)
    {
        patternConverter(ellipse.pattern);
        glColor3d(ellipse.red/255.0,ellipse.green/255.0,ellipse.blue/255.0);
        midpointEllipseDrawingAlgorithm(ellipse.center,ellipse.radius_x,ellipse.radius_y);
    }
    glFlush();
}

void mouseCallback(int button,int state,int x,int y)
{
    static pointPair currentPos;
    static pointPair center;
    static float radius_x;
    static int number_of_clicks = 0;
    
    int adjusted_x = x - halfWidth;
    int adjusted_y = -(y - halfHeight);

    
    if(button == GLUT_LEFT_BUTTON and state == GLUT_DOWN)
    {
        currentPos = {double(adjusted_x),double(adjusted_y)};
        if(number_of_clicks==0)
        {
            number_of_clicks++;
            center = {double(adjusted_x),double(adjusted_y)};
            drawGuidelines(center);

        }
        else if(number_of_clicks==1)
        {
            number_of_clicks++;
            radius_x = std::sqrt(std::pow(center.x-currentPos.x,2)+std::pow(center.y-currentPos.y,2));
        }
        else
        {
            glColor3d(red_val/255.0,green_val/255.0,blue_val/255.0);
            double distance = std::sqrt(std::pow(center.x-currentPos.x,2)+std::pow(center.y-currentPos.y,2));
            // midpointEllipseDrawingAlgorithm(center,radius_x,distance);
            number_of_clicks=0;
            handler.writeToCSV(center.x,center.y,radius_x,distance,char(std::toupper(pattern_box->get_text().back())),red_val,blue_val,green_val);
            clearScreen();
            redrawScreenFromFile();
        }

    }
    glFlush();
    glutPostRedisplay();
}

void patternConverter(std::string input_pattern)
{
    char code = char(std::toupper(input_pattern.back()));
    if(not isxdigit(code))
    {
        return;
    }
    std::string input = "0x" + std::string(1,code);
    unsigned int converted = std::stoul(input,nullptr,16);
    hex_pattern = pattern(converted);
}

void patternSelectorCallback(const int id)
{
    patternConverter(pattern_box->get_text());
}

void clearScreen()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glutPostRedisplay();
}

void clearScreenCallback(int id)
{
    glClear(GL_COLOR_BUFFER_BIT);
    handler.clearFile();
    glutPostRedisplay();
}

void undoCallback(const int id)
{
    ignore_counter++;
    int number_of_lines_in_file = handler.getNumberOfLines();
    if(ignore_counter>number_of_lines_in_file) ignore_counter = number_of_lines_in_file;
    redrawScreenFromFile();
}

void redoCallback(const int id)
{
    ignore_counter--;
    if(ignore_counter<0) ignore_counter = 0;
    redrawScreenFromFile();
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
    int main_window = glutCreateWindow("Ellipse");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    halfHeight = glutGet(GLUT_WINDOW_HEIGHT)/2;
    halfWidth = glutGet(GLUT_WINDOW_WIDTH)/2;
    gluOrtho2D(-halfWidth, halfWidth, -halfHeight, halfHeight);
    // gluOrtho2D(-20, 20, -20, 20);
    GLUI_Master.set_glutIdleFunc(nullptr);
    GLUI_Master.set_glutMouseFunc(mouseCallback);
    GLUI_Master.set_glutDisplayFunc(display);
    GLUI *gluiWindow = GLUI_Master.create_glui_subwindow(main_window,GLUI_SUBWINDOW_TOP);
    gluiWindow->set_main_gfx_window(main_window);

    pattern_box = gluiWindow->add_edittext("Pattern",GLUI_EDITTEXT_TEXT,nullptr,-1,patternSelectorCallback);
    pattern_box->set_text("F");

    gluiWindow->add_column(true);
    
    color_rollout = gluiWindow->add_rollout("Color",0);
    color_rollout->set_w(163);
    red_spinner = gluiWindow->add_spinner_to_panel(color_rollout,"Red",GLUI_SPINNER_INT,&red_val);
    blue_spinner = gluiWindow->add_spinner_to_panel(color_rollout,"Blue",GLUI_SPINNER_INT,&blue_val);
    green_spinner = gluiWindow->add_spinner_to_panel(color_rollout,"Green",GLUI_SPINNER_INT,&green_val);
    red_spinner->set_int_limits(0,255,GLUI_LIMIT_WRAP);
    blue_spinner->set_int_limits(0,255,GLUI_LIMIT_WRAP);
    green_spinner->set_int_limits(0,255,GLUI_LIMIT_WRAP);

    gluiWindow->add_column(true);
    gluiWindow->add_column(false);
    undo_button = gluiWindow->add_button("Undo",-1,undoCallback);
    undo_button->set_w(20);
    gluiWindow->add_column(false);
    redo_button = gluiWindow->add_button("Redo",-1,redoCallback);
    redo_button->set_w(20);
    gluiWindow->add_column(false);
    clear_screen_button = gluiWindow->add_button("Clear",-1,clearScreenCallback);
    clear_screen_button->set_w(20);
    glutMainLoop();
    return 0;
}