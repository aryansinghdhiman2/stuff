#include <iostream>
#include <GL/freeglut.h>
#include <vector>
using namespace std;
vector<float> points;
vector<float> controlPoints;
int initalIndex = 0;
int m;
int n;
void myInit()
{
// OpenGL initialization
glClearColor(1.0, 1.0, 1.0, 0.0);
glColor3f(0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-300.0, 300.0, -300.0, 300.0);
}
void drawAxes()
{
// Draw coordinate axes
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glColor3f(0.0, 0.0, 0.0);
glBegin(GL_LINES);
glVertex2i(300, 0);
glVertex2i(-300, 0);
glVertex2i(0, 300);
glVertex2i(0, -300);
glEnd();
}
void drawInterploatedPoints()
{
// Function that plots points lying on the curve on the screen
glPointSize(1);
glBegin(GL_POINTS);
glColor3f(1.0, 0.0, 0.0);
for (int i = 2; i < points.size(); i += 2)
{
float x = points[i - 2];
float y = points[i - 1];
glVertex2f(x, y);
}
glEnd();
}
void drawContolPoints()
{
// Function that plots control Points on window
glPointSize(4);
glBegin(GL_POINTS);
glColor3f(0.0, 0.0, 1.0);
for (int i = 0; i < controlPoints.size() / 2; i++)
{
float x = controlPoints[i * 2];
float y = controlPoints[i * 2 + 1];
glVertex2f(x, y);
}
glEnd();
}
void plot()
{
// Function that plots points on screen
drawAxes();
drawInterploatedPoints();
drawContolPoints();
}
float spline(float t, float k, int m)
{
// Function that calculates the values of the coffiecientof each point
if (m == 1)
{
if ((k) < t && (k + 1) >= t)
return 1;
else
return 0;
}
float ans1 = (t - k) / ((k + m - 1) - k) * spline(t, k, m - 1);
float ans2 = ((k + m) - t) / ((k + m) - (k + 1)) * spline(t, k + 1, m -
1);
return ans1 + ans2;
}
void generateCurve()
{
// Function that generates the b- spline curve
int n = controlPoints.size() / 2;
int knots = n + m - 2;
int lineSegment = 0;
int isTrue = 0;
points.push_back(0.0);
points.push_back(0.0);
for (int t = 0; t <= knots; t++)
{
for (int tx = 0; tx < 1000; tx += 1)
{
for (int j = 0; j < n; j++)
{
float x1 = controlPoints[j * 2];
float y1 = controlPoints[j * 2 + 1];
float coefficient = spline((float)t + ((float)tx / 1000), j + 
m - 1, m);
points[lineSegment * 2] += x1 * coefficient;
points[lineSegment * 2 + 1] += y1 * coefficient;
}
if (isTrue == 1)
{
points.push_back(0.0);
points.push_back(0.0);
lineSegment++;
}
else
{
if (
points[lineSegment * 2] - controlPoints[initalIndex] < 1
&&
points[lineSegment * 2] - controlPoints[initalIndex] > -1
&&
points[lineSegment * 2 + 1] - controlPoints[1 + 
initalIndex] < 1 &&
points[lineSegment * 2 + 1] - controlPoints[1 + 
initalIndex] > -1)
{
isTrue = 1;
}
points[lineSegment * 2] = 0.0;
points[lineSegment * 2 + 1] = 0.0;
}
}
}
plot();
glFlush();
}
void myScreen(void)
{
// Function that display screen
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
plot();
glFlush();
}
void myMouse(int button, int state, int x, int y)
{
// Mouse callback function to handle mouse events
x = x - 300;
y = 300 - y;
if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
{
controlPoints.push_back(x);
controlPoints.push_back(y);
if (controlPoints.size() - initalIndex == 2)
{
for (int i = 1; i < m - 1; i++)
{
controlPoints.push_back(x);
controlPoints.push_back(y);
}
}
}
if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
{
for (int i = 0; i < m - 1; i++)
{
controlPoints.push_back(x);
controlPoints.push_back(y);
}
generateCurve();
}
}
int main(int argc, char **argv)
{
cout << "---B-Spline Curves---" << endl;
cout << endl;
cout << " 1. Linear" << endl;
cout << " 2. Quadratic" << endl;
cout << " 3. Cubic" << endl;
cout << endl;
cout << "Enter the appropiate number: ";
cin >> n;
m = n + 1;
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition(100, 100);
glutInitWindowSize(600, 600);
glutCreateWindow("B-Spline Curve");
myInit();
glutMouseFunc(myMouse);
glutDisplayFunc(myScreen);
glutMainLoop();
return 1;
}