#include <GL/freeglut.h> // GLUT, includes glu.h and gl.h
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <bitset>
#include <GL/glui.h>

typedef std::bitset<4> pattern;
pattern hex_pattern("1111");
int red_val = 255,blue_val = 255,green_val = 255;
int halfHeight;
int halfWidth;

GLUI_EditText* pattern_box;
GLUI_Rollout* color_rollout;
GLUI_Spinner* red_spinner;
GLUI_Spinner* blue_spinner;
GLUI_Spinner* green_spinner;

GLUI_Button* clear_screen_button;

struct pointPair {
    double x;
    double y;
    pointPair(double a,double b): x(a),y(b) {}
    pointPair(): x(0),y(0) {}

};

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

void ShiftAndDrawPoint(pointPair originalPoint,pointPair shiftBy)
{
    glBegin(GL_POINTS);
    glVertex2d(originalPoint.x+shiftBy.x,originalPoint.y+shiftBy.y);
    std::cout<<originalPoint.x+shiftBy.x<<","<<originalPoint.y+shiftBy.y<<'\n';
    glEnd();
}

void drawCirclePoint(const pointPair& currentPoint,const pointPair center)
{
    glBegin(GL_POINTS);
    ShiftAndDrawPoint({currentPoint.x,currentPoint.y},center);
    ShiftAndDrawPoint({currentPoint.y,currentPoint.x},center);
    ShiftAndDrawPoint({currentPoint.y,-currentPoint.x},center);
    ShiftAndDrawPoint({currentPoint.x,-currentPoint.y},center);
    ShiftAndDrawPoint({-currentPoint.x,-currentPoint.y},center);
    ShiftAndDrawPoint({-currentPoint.y,-currentPoint.x},center);
    ShiftAndDrawPoint({-currentPoint.y,currentPoint.x},center);
    ShiftAndDrawPoint({-currentPoint.x,currentPoint.y},center);
    glEnd();
}

void midpointCircleDrawingAlgorithm(const pointPair center,float radius)
{
    int pattern_pos = hex_pattern.size()-1;

    float pk = 5.0/4.0 - radius;
    pointPair currentPoint = {0,radius};
    
    if(hex_pattern.test(pattern_pos))
    {
        drawCirclePoint(currentPoint,center);
    }
    
    while (currentPoint.x < currentPoint.y)
    {
        if(pk < 0)
        {
            currentPoint.x=currentPoint.x+1;
            if(hex_pattern.test(pattern_pos))
            {
                drawCirclePoint(currentPoint,center);
            }
            pk = pk + 2*currentPoint.x + 1;
        }
        else
        {
            currentPoint.x=currentPoint.x+1;
            currentPoint.y=currentPoint.y-1;
            if(hex_pattern.test(pattern_pos))
            {
                drawCirclePoint(currentPoint,center);
            }
            pk = pk + 2*(currentPoint.x - currentPoint.y) + 1;
        }
        pattern_pos--;
        if(pattern_pos == -1 ) pattern_pos = hex_pattern.size()-1;
    }
    glFlush();
       
}

void mouseCallback(int button,int state,int x,int y)
{
    glColor3d(red_val/255.0,green_val/255.0,blue_val/255.0);

    static pointPair currentPos;
    static pointPair center;
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
        }
        else
        {
            double distance = std::sqrt(std::pow(center.x-currentPos.x,2)+std::pow(center.y-currentPos.y,2));
            midpointCircleDrawingAlgorithm(center,distance);
            number_of_clicks=0;
        }

    }
    glFlush();
    glutPostRedisplay();
}

void patternSelectorCallback(const int id)
{;
    char code = char(std::toupper(pattern_box->get_text().back()));
    if(not isxdigit(code))
    {
        return;
    }
    std::string input = "0x" + std::string(1,code);
    unsigned int converted = std::stoul(input,nullptr,16);
    hex_pattern = pattern(converted);
}

void clearScreenCallback(int id)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glutPostRedisplay();
}
bool once = false;
void display()
{
    drawAxes();
    if(not once)
    {
        midpointCircleDrawingAlgorithm({0,0},2);
        once=true;
    }
    // midpointCircleDrawingAlgorithm({0,0},2);
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(-1, -1);
    int main_window = glutCreateWindow("Circle");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    halfHeight = glutGet(GLUT_WINDOW_HEIGHT)/2;
    halfWidth = glutGet(GLUT_WINDOW_WIDTH)/2;
    gluOrtho2D(-halfWidth, halfWidth, -halfHeight, halfHeight);
    
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
    clear_screen_button = gluiWindow->add_button("Clear",-1,clearScreenCallback);
    clear_screen_button->set_w(20);
    glutMainLoop();
    return 0;
}