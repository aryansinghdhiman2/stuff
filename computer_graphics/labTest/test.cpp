#include <GL/freeglut.h> 
#include <iostream>
#include <cstdlib>
#include <array>

struct pointPair {
    double x;
    double y;
    pointPair(double a,double b): x(a),y(b) {}
    pointPair(): x(0),y(0) {}

};

int halfHeight;
int halfWidth;
int side;
int depth;

void drawSquare(const std::array<pointPair,4> vertices,const std::array<int,3> color,int depth)
{
    glColor3f(color[0]/255.0,color[1]/255.0,color[2]/255.0);
    if(depth > 0)
    {
        glBegin(GL_POLYGON);
        glVertex2i(vertices.at(0).x,vertices.at(0).y);
        glVertex2i(vertices.at(1).x,vertices.at(1).y);
        glVertex2i(vertices.at(2).x,vertices.at(2).y);
        glVertex2i(vertices.at(3).x,vertices.at(3).y);
        glEnd();

        std::array<pointPair,4> internal_vert;
        internal_vert.at(0).x = (vertices.at(0).x + vertices.at(1).x)/2;
        internal_vert.at(0).y = (vertices.at(0).y + vertices.at(1).y)/2;

        internal_vert.at(1).x = (vertices.at(1).x + vertices.at(2).x)/2;
        internal_vert.at(1).y = (vertices.at(1).y + vertices.at(2).y)/2;

        internal_vert.at(2).x = (vertices.at(2).x + vertices.at(3).x)/2;
        internal_vert.at(2).y = (vertices.at(2).y + vertices.at(3).y)/2;

        internal_vert.at(3).x = (vertices.at(3).x + vertices.at(0).x)/2;
        internal_vert.at(3).y = (vertices.at(3).y + vertices.at(0).y)/2;

        std::array<int,3> other_color;
        other_color.at(0) = rand() % 255;
        other_color.at(1) = rand() % 255;
        other_color.at(2) = rand() % 255;
        drawSquare(internal_vert,other_color,depth-1);
    }

}

void display()
{
    // glClear(GL_COLOR_BUFFER_BIT);
    static bool once = false;

    std::array<pointPair,4> vertices;
    vertices.at(0) = pointPair(side/2,side/2);
    vertices.at(1) = pointPair(-side/2,side/2);
    vertices.at(2) = pointPair(-side/2,-side/2);
    vertices.at(3) = pointPair(side/2,-side/2);

    std::array<int,3> color;
    color.at(0) = rand() % 255;
    color.at(1) = rand() % 255;
    color.at(2) = rand() % 255;

    if(not once)
    {
        drawSquare(vertices,color,depth+1);
        once = true;
    }
    glFlush();
}

int main(int argc, char **argv)
{

    std::cout<<"Enter Length of Side: ";
    std::cin>>side;
    std::cout<<"Enter Number of Squares:";
    std::cin>>depth;
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(-1, -1);
    int main_window = glutCreateWindow("Circle");


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    halfHeight = glutGet(GLUT_WINDOW_HEIGHT)/2;
    halfWidth = glutGet(GLUT_WINDOW_WIDTH)/2;
    gluOrtho2D(-halfWidth, halfWidth, -halfHeight, halfHeight);
    glutDisplayFunc(display);
    srand(time(0));
    glutMainLoop();
    return 0;
}