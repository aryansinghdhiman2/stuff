#include<iostream>
#include<vector>
#include<math.h>
#include<GL/glut.h>
using namespace std;

vector<int> x;
vector<int> y;

int direction=1;

double anglee = 0;
int txc = 0;
int tyc = 0;

int sxc = 1;
int syc = 1;

int txxc = 0;
int tyyc = 0;

float rr = 1.0;
float gg = 1.0;
float bb = 1.0;

void init(void)
{
    glutInitWindowSize(500,500);
    // glutInitWindowPosition(1000,130);
    glutCreateWindow("Transformations");
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-250,250,-250,250,1,-1);
}

void displayAxis(void)
{
     glPointSize(1);
     glColor3f(1.0,1.0,1.0);
     glBegin(GL_LINES);
     glVertex2i(0,250);
     glVertex2i(0,-250);
     glVertex2i(250,0);
     glVertex2i(-250,0);
     glEnd();
     glFlush();
}

void translation(vector<int> x, vector<int> y , int tx ,int ty) {
    glColor3f(rr, gg, bb);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < x.size(); i++) {
        glVertex2i(x[i] + tx , y[i] + ty);
    }
    glEnd();
    glFlush();
}

void scaling(vector<int> x, vector<int> y, int sx, int sy) {
    glColor3f(rr, gg, bb);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < x.size(); i++) {
        glVertex2i(round(x[i] * sx),round(y[i] * sy));
    }
    glEnd();
    glFlush();
}

void rotation(vector<int> x, vector<int> y, double(angle)) {
    angle = direction * angle * 3.1416 / 180;
    glColor3f(rr, gg, bb);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < x.size(); i++) {
        glVertex2i(round((x[i] * cos(angle)) - (y[i] * sin(angle))),round((x[i] * sin(angle)) + (y[i] * cos(angle))));
    }
    glEnd();
    glFlush();
}

void pivotscaling(vector<int> x, vector<int> y, int tx1, int ty1, int sx, int sy) {
    glColor3f(rr, gg, bb);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < x.size(); i++) {
        glVertex2i(round(x[i] * sx - sx * tx1 + tx1),round(y[i] * sy - sy * ty1 + ty1));
    }
    glEnd();
    glFlush();
}

void pivotrotation(vector<int> x, vector<int> y, int tx1, int ty1, double angle) {
    angle = direction * angle * 3.1416 / 180;
    glColor3f(rr, gg, bb);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < x.size(); i++) {
        glVertex2i (round( x[i] * cos(angle) - y[i] * sin(angle) - tx1 * cos(angle) + ty1 * sin(angle) + tx1),round(x[i] * sin(angle) + y[i] * cos(angle) - tx1 * sin(angle) - ty1 * cos(angle) + ty1));
    }
    glEnd();
    glFlush();
}

void drawShape() {
    glPointSize(2);
    int n,xvalue,yvalue;
    cout << "Number of Points : ";
    cin >> n;
    cout << "Enter Points : ";
    for(int i=0; i<n; i++){
        cin >> xvalue;
        cin >> yvalue;
        x.push_back(xvalue);
        y.push_back(yvalue);
    }

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < x.size(); i++) {
        glColor3f(1.0,1.0,1.0);
        glVertex2i(x[i], y[i]);
    }
    glEnd();
    glFlush();
}

void setAlgorithm(int id)
{
    switch (id)
    {
    case 1:
        translation(x, y, txc, tyc);
        break;
    case 2:
        scaling(x, y, sxc, syc);
        break;
    case 3:
        pivotscaling(x, y, txxc, tyyc, sxc, syc);
        break;
    case 4:
        rotation(x, y, anglee);
        break;
    case 5:
        pivotrotation(x, y, txxc, tyyc, anglee);
        break;
    }
}

void setColor(int c){
    switch (c){
    
    case 1:
        rr = 0.0;
        gg = 0.0;
        bb = 1.0;
        break;
   
}}
void setAngle(int a){
    switch (a){
    case 1:
        anglee = 30;
        break;
    case 2:
        anglee = 45;
        break;
    case 3:
        anglee = 60;
        break;
    case 4:
        anglee = 90;
        break;
    case 5:
        anglee = 180;
        break;
    
     case 6:
        anglee = 270;
        break;
    }
}

void setScale(int s){
    switch (s){
    case 1:
        sxc = 2;
        syc = 2;
        break;
    case 2:
        sxc = 3;
        syc = 3;
        break;
    case 3:
        sxc = 4;
        syc = 4;
        break;
    case 4:
        sxc = 0.5;
        syc = 0.5;
        break;
    }
}

void setTranslate(int t){
    switch (t){
    case 1:
        txc = 15;
        tyc = 15;
        break;
    case 2:
        txc = 10;
        tyc = 10;
        break;
    case 3:
        txc = 20;
        tyc = 20;
        break;
    }
}

void setPoint(int p){
    switch (p){
    case 1:
        txxc = x[0];
        tyyc = y[0];
        break;
    case 2:
        txxc = x[1];
        tyyc = y[1];
        break;
    case 3:
        txxc = x[2];
        tyyc = y[2];
        break;
    case 4:
        txxc = x[3];
        tyyc = y[3];
        break;
    }
}

void setDirection(int d){
    switch (d){
    case 1:
        direction = 1;
        break;
    case 2:
        direction = -1;
        break;
    }
}

void menu(){
    int algo = glutCreateMenu(setAlgorithm);
    glutAddMenuEntry("Translation", 1);
    glutAddMenuEntry("Scaling", 2);
    glutAddMenuEntry("Scaling About Point", 3);
    glutAddMenuEntry("Rotation", 4);
    glutAddMenuEntry("Rotation About Point", 5);
    glutCreateMenu(setAlgorithm);

    int angle = glutCreateMenu(setAngle);
    glutAddMenuEntry("30", 1);
    glutAddMenuEntry("45", 2);
    glutAddMenuEntry("60", 3);
    glutAddMenuEntry("90", 4);
    glutAddMenuEntry("180", 5);
      glutAddMenuEntry("270", 6);
    glutCreateMenu(setAngle);

    int scale = glutCreateMenu(setScale);
    glutAddMenuEntry("2", 1);
    glutAddMenuEntry("3", 2);
    glutAddMenuEntry("4", 3);
    glutAddMenuEntry("0.5", 4);
    glutCreateMenu(setScale);

    int point = glutCreateMenu(setPoint);
    glutAddMenuEntry("1'st", 1);
    glutAddMenuEntry("2'st", 2);
    glutAddMenuEntry("3'st", 3);
    glutAddMenuEntry("4'st", 4);
    glutCreateMenu(setPoint);

    int translate = glutCreateMenu(setTranslate);
    glutAddMenuEntry("15", 1);
    glutAddMenuEntry("10", 2);
    glutAddMenuEntry("20", 3);
    glutCreateMenu(setTranslate);

    int direction = glutCreateMenu(setDirection);
    glutAddMenuEntry("Anticlockwise", 1);
    glutAddMenuEntry("Clockwise", 2);
    glutCreateMenu(setDirection);
     glutAddSubMenu("Translate vector", translate);
   
    glutAddSubMenu("Scaling Factor", scale);
      glutAddSubMenu("Rotation angle", angle);
     glutAddSubMenu("Direction", direction);
   
    glutAddSubMenu("About Point ", point);
    glutAddSubMenu("Transformation", algo);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void plotPoints(int x,int y)
{
     glColor3f(0.0,0.0,1.0);
     glPointSize(2);
     glBegin(GL_POINTS);
     glVertex2i(x-(250),(250)-y);
     glEnd();
     glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE || GLUT_RGB);
    init();
    glutDisplayFunc(displayAxis);
    drawShape();
    menu();
    glutMainLoop();
}