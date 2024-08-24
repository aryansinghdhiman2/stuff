#include <GL/freeglut.h> // GLUT, includes glu.h and gl.h
#include <GL/glui.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <string>
typedef std::bitset<4> pattern;


int halfHeight;
int halfWidth;
int red_val = 255,blue_val = 255,green_val = 255;
int thickness = 1;
pattern hex_pattern("1111");

GLUI_Listbox* algorithm_box;

GLUI_Rollout* color_rollout;
GLUI_Spinner* red_spinner;
GLUI_Spinner* blue_spinner;
GLUI_Spinner* green_spinner;

GLUI_EditText* pattern_box;
GLUI_Spinner* thickness_box;

GLUI_Button* clear_screen_button;

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
        glVertex2f(halfWidth,0);
        glVertex2f(-halfWidth,0);
        glVertex2f(0,halfHeight);
        glVertex2f(0,-halfHeight);
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
 
        // glVertex2f(a.x,a.y);
        // glVertex2f(b.x,b.y);
 
    for(int i = 1; i<line_length_estimate;i++)
    {
        currentPos.x += x_increment;
        currentPos.y += y_increment;
        if(hex_pattern.test(pattern_pos))
        {
            glVertex2f(std::round(currentPos.x),std::round(currentPos.y));
        }
        pattern_pos--;
        if(pattern_pos == -1 ) pattern_pos = hex_pattern.size()-1;
    }
 
    glEnd();
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
 
    //     glVertex2f(a.x,a.y);
    //     glVertex2f(b.x,b.y);
 
    for(int i = 1; i<line_length_estimate;i++)
    {
        currentPos.x += x_increment;
        currentPos.y += y_increment;
        if(hex_pattern.test(pattern_pos))
        {
            glVertex2f(std::round(currentPos.x),std::round(currentPos.y));
        }
        pattern_pos--;
        if(pattern_pos == -1) pattern_pos = hex_pattern.size()-1;
    }
 
    glEnd();
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

        // glVertex2f(a.x,a.y);
        // glVertex2f(b.x,b.y);

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
            glVertex2f(currentPoint.x,currentPoint.y);
        }
        pattern_pos--;
        if(pattern_pos == -1) pattern_pos = hex_pattern.size()-1;
    }
    glEnd();

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
    glColor3f(red_val/255.0,green_val/255.0,blue_val/255.0);
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
            while((i)<=float(std::abs(thickness/2)))
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

void algorithmSelectCallback(const int id)
{
    int choice = algorithm_box->get_int_val();
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
void display()
{
    drawAxes();
    glFlush();
}

int main(int argc, char **argv)
{
    algorithmFunc = simpleDDApattern;

    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(250, 100);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    int main_window = glutCreateWindow("Simple DDA Mouse");

    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
    glDisable(GL_LINE_SMOOTH);
    glDisable(GL_BLEND);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    halfHeight = glutGet(GLUT_WINDOW_HEIGHT)/2;
    halfWidth = glutGet(GLUT_WINDOW_WIDTH)/2;
    glViewport(0, 0, halfWidth*2, halfHeight*2);
    gluOrtho2D(-halfWidth, halfWidth, -halfHeight, halfHeight);

    GLUI_Master.set_glutIdleFunc(nullptr);
    GLUI_Master.set_glutMouseFunc(anotherMouseCallback); 
    GLUI *gluiWindow = GLUI_Master.create_glui_subwindow(main_window,GLUI_SUBWINDOW_TOP);
    gluiWindow->set_main_gfx_window(main_window);

    gluiWindow->add_column(false);

    algorithm_box = gluiWindow->add_listbox("Algorithm ",nullptr,-1,algorithmSelectCallback);
    algorithm_box->add_item(0,"Simple DDA");
    algorithm_box->add_item(1,"Symmeterical DDA");
    algorithm_box->add_item(2,"Bresenham/Midpoint");

    gluiWindow->add_column(true);

    color_rollout = gluiWindow->add_rollout("Color",false);
    color_rollout->set_w(163);
    red_spinner = gluiWindow->add_spinner_to_panel(color_rollout,"Red",GLUI_SPINNER_INT,&red_val);
    blue_spinner = gluiWindow->add_spinner_to_panel(color_rollout,"Blue",GLUI_SPINNER_INT,&blue_val);
    green_spinner = gluiWindow->add_spinner_to_panel(color_rollout,"Green",GLUI_SPINNER_INT,&green_val);
    red_spinner->set_int_limits(0,255,GLUI_LIMIT_WRAP);
    blue_spinner->set_int_limits(0,255,GLUI_LIMIT_WRAP);
    green_spinner->set_int_limits(0,255,GLUI_LIMIT_WRAP);

    gluiWindow->add_column(true);

    pattern_box = gluiWindow->add_edittext("Pattern",GLUI_EDITTEXT_TEXT,nullptr,-1,patternSelectorCallback);
    pattern_box->set_text("F");
    gluiWindow->add_column(true);

    thickness_box = gluiWindow->add_spinner("Thickness",GLUI_SPINNER_INT,&thickness);

    gluiWindow->add_column(true);
    gluiWindow->add_column(false);
    clear_screen_button = gluiWindow->add_button("Clear",-1,clearScreenCallback);
    clear_screen_button->set_w(20);
    // thickness_box->set_int_limits(0,50,GLUI_LIMIT_CLAMP);
    // glEnable(GL_BLEND);
    glutDisplayFunc(display);
    // glutSwapBuffers();
    glutMainLoop();
    return 0;
}



