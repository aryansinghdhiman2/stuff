#include<stdlib.h>
#include<stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;
// float x1, x2, y1, y2;

void DDA(float x1, float x2, float y1, float y2) {
  float dy, dx, step, x, y, k, Xin, Yin;
  dx = x2 - x1;
  dy = y2 - y1;
  if (abs(dx) > abs(dy)) {
    step = abs(dx);
  } else
    step = abs(dy);
  Xin = dx / step;
  Yin = dy / step;
  x = x1;
  y = y1;
  glBegin(GL_POINTS);
  // printf("%f", &x_adj);
  // printf("%f",&y_adj);
  // glVertex2i(x_adj, y_adj);
  glEnd();
  for (k = 1; k <= step; k++) {
    x = x + Xin;
    y = y + Yin;
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
  }
  glFlush();
}
void display(){
  // glClear(GL_COLOR_BUFFER_BIT);
  glFlush();
}
void myInit (void) {
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  printf("%d, %d \n",glutGet(GLUT_WINDOW_WIDTH)/2,glutGet(GLUT_WINDOW_HEIGHT)/2);
  gluOrtho2D(-glutGet(GLUT_WINDOW_WIDTH)/2, glutGet(GLUT_WINDOW_WIDTH)/2,-glutGet(GLUT_WINDOW_HEIGHT)/2, glutGet(GLUT_WINDOW_HEIGHT)/2);
  // gluOrtho2D(0,GLint(640),0,GLint(480));
}

void mouseHandler(int button, int state,int x,int y){
    x = x-(glutGet(GLUT_WINDOW_WIDTH)/2);
    y = -(y-(glutGet(GLUT_WINDOW_HEIGHT)/2));
    static int x1,x2, y1,y2;
    if(button == GLUT_LEFT_BUTTON){
        x1=x;
        y1=y;
        x2=0;
        y2=0;
    }
    else if (button == GLUT_RIGHT_BUTTON){
        x2=x;
        y2=y;
    }
    {
    DDA(x1,x2,y1,y2);
    }
    glFlush();
}

int main(int argc, char ** argv) {

  glutInit( & argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(640, 480);
  // glutInitWindowPosition(100, 150);
  glutCreateWindow("");
  glutDisplayFunc(display);
  glutMouseFunc(mouseHandler);
  myInit ();
  
  glutMainLoop();
}