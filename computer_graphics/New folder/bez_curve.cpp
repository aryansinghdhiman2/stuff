#include <iostream>
#include <vector>
#include <GL/freeglut.h>
#include <GL/glui.h>
#include <cmath>
using namespace std;
int points = 0;
int counter = 1;
bool polygonMade = false;
vector<float> x_coordinates;
vector<float> y_coordinates;
void myInit()
{
// Initialization of the window
glClearColor(1.0, 1.0, 1.0, 0.0);
glColor3f(0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-300.0, 300.0, -300.0, 300.0);
}
void drawAxes()
{
// Function to draw coordinate axes
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glColor3f(0.0, 0.0, 0.0);
glBegin(GL_LINES);
glVertex2i(300, 0);
glVertex2i(-300, 0);
glVertex2i(0, 300);
glVertex2i(0, -300);
glEnd();
glutPostRedisplay();
}
int factorial(int n)
{
// Function to calculate factorial of a number
if (n <= 1)
return 1;
else
return n * factorial(n - 1);
}
float nCr(float n, float k)
{
// Function to calculate combinations (n choose k)
float variable;
variable = factorial(n) / (factorial(k) * factorial(n - k));
return variable;
}
pair<float, float> bezierCurve(vector<float> x_coordinates, vector<float> 
y_coordinates, double t)
{
// Function to calculate a point on the Bezier curve at a given parameter 

float x = 0, y = 0;
for (int i = 0; i < points; i++)
{
x = x + nCr(points - 1, i) * pow(t, i) * pow((1 - t), (points - 1 -
i)) * x_coordinates[i];
y = y + nCr(points - 1, i) * pow(t, i) * pow((1 - t), (points - 1 -
i)) * y_coordinates[i];
}
return {x, y};
}
void myScreen()
{
glFlush();
}
void drawLine(float x1, float y1, float x2, float y2)
{
// Function to draw a line between two points
glColor3f(0.0, 0.0, 1.0);
glBegin(GL_LINES);
glVertex2f(x1, y1);
glVertex2f(x2, y2);
glEnd();
glFlush();
}
void myMouse(int button, int state, int x, int y)
{
// Mouse callback function to handle mouse events
x = x - 300;
y = 300 - y;
if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && !polygonMade)
{
if (counter <= points)
{
x_coordinates.push_back(x);
y_coordinates.push_back(y);
// Draw the control point
glColor3f(0.0, 0.0, 0.0);
glPointSize(2);
glBegin(GL_POINTS);
glVertex2f(x, y);
glEnd();
glFlush();
counter++;
}
else
{
polygonMade = true;
}
}
else if (polygonMade)
{
// Draw the Bezier curve using the defined control points
float x1 = x_coordinates[0];
float y1 = y_coordinates[0];
for (float i = 0.0; i <= 1.0; i += 0.01)
{
pair<float, float> p = bezierCurve(x_coordinates, y_coordinates, 
i);
drawLine(x1, y1, p.first, p.second);
x1 = p.first;
y1 = p.second;
}
}
}
int main(int argc, char **argv)
{
// Get the number of control points from the user
cout << "Enter Number of Control Points: ";
cin >> points;
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition(100, 100);
glutInitWindowSize(600, 600);
glutCreateWindow("Bezier Curve");
myInit();
drawAxes();
glutDisplayFunc(myScreen);
glutMouseFunc(myMouse);
glutMainLoop();
return 0;
}