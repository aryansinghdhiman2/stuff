#include <GL/glut.h>
#include <stdio.h>

struct Color {
    GLfloat r;
    GLfloat g;
    GLfloat b;
};

int halfHeight;
int halfWidth;

void draw_polygon(){
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_LINES);
    glVertex2f(0.0, 0.0);
    glVertex2f(100.0, 0.0);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(100.0, 0.0);
    glVertex2f(100.0, 80.0);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(100.0, 80.0);
    glVertex2f(0.0, 80.0);

    glBegin(GL_LINES);
    glVertex2f(0.0, 80.0);
    glVertex2f(0.0, 0.0);

    glEnd();

}


Color getPixelColor(GLint x, GLint y) {
    Color color;
    glReadPixels(x + halfWidth, y + halfHeight, 1, 1, GL_RGB, GL_FLOAT, &color);
    // printf("%f",color.r);
    // printf("%f",color.g);
    // printf("%f",color.g);

    return color;
}

void setPixelColor(GLint x, GLint y, Color color) {
    glColor3f(color.r, color.g, color.b);
    // glBegin(GL_POINTS);
    // glVertex2i(x, y);
    // glEnd();
    glRasterPos2i(x,y);
    glDrawPixels(1,1,GL_RGB,GL_FLOAT,&color);
    glFlush();
}

void boundaryFill(int x , int y, Color fillColor, Color boundaryColor){

    Color interiorColor;
    interiorColor = getPixelColor(x , y);

    if ((interiorColor.r != fillColor.r || interiorColor.g != fillColor.g || interiorColor.b != fillColor.b) &&
        (interiorColor.r != boundaryColor.r || interiorColor.g != boundaryColor.g || interiorColor.b!= boundaryColor.b))
     {
        setPixelColor(x, y, fillColor);
        boundaryFill(x+1, y, fillColor, boundaryColor);
        boundaryFill(x-1, y, fillColor, boundaryColor);
        boundaryFill(x, y+1, fillColor, boundaryColor);
        boundaryFill(x, y-1, fillColor, boundaryColor);

     }
    return;

}

void onMouseClick(int button, int state, int x, int y)
{
    Color boundaryColor = {1.0f, 1.0f, 1.0f};
    Color fillColor = {1.0f, 0.0f, 0.0f};

    x = x - (glutGet(GLUT_WINDOW_WIDTH) / 2);
    y = -(y - (glutGet(GLUT_WINDOW_HEIGHT) / 2));

    boundaryFill(x, y, fillColor, boundaryColor);
}


void myInit (void) {
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-glutGet(GLUT_WINDOW_WIDTH)/2, glutGet(GLUT_WINDOW_WIDTH)/2,-glutGet(GLUT_WINDOW_HEIGHT)/2, glutGet(GLUT_WINDOW_HEIGHT)/2);
 
}

void display(){
  glFlush();
}


int main(int argc, char ** argv) {

  glutInit( & argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(640, 480);
  glutCreateWindow("");
  halfHeight = glutGet(GLUT_WINDOW_HEIGHT)/2;
    halfWidth = glutGet(GLUT_WINDOW_WIDTH)/2;
  glutDisplayFunc(display);
  glutMouseFunc(onMouseClick);
  myInit ();
  draw_polygon();
  glutMainLoop();
}
