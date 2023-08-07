#include<stdlib.h>
#include<stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

float x1, x2, y1, y2;

void display(void) {
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
  // glPointSize(5);
  glBegin(GL_POINTS);
  glVertex2i(x, y);
  glEnd();


  for (k = 1; k <= step; k++) {
    x = x + Xin;
    y = y + Yin;
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
  }
  glFlush();
}

void myInit (void) {
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  // gluOrtho2D(0.0, 640.0, 0.0, 480.0);
  gluOrtho2D(-320.0, 320.0, -240.0, 240.0);
}

int main(int argc, char ** argv) {

  printf("Value of x1 : ");
  scanf("%f", & x1);
  printf("Value of y1 : ");
  scanf("%f", & y1);
  printf("Value of x2 : ");
  scanf("%f", & x2);
  printf("Value of y2 : ");
  scanf("%f", & y2);

  glutInit( & argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(100, 150);
  glutCreateWindow("");
  
  myInit ();
  glutDisplayFunc(display);
  glutMainLoop();
}