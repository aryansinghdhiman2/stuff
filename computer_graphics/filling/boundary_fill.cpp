#include <GL/freeglut.h> // GLUT, includes glu.h and gl.h
#include <GL/glui.h>
#include<algorithm>

#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int halfHeight;
int halfWidth;
vector<float>vertx;
vector<float>verty;
float seed_x;
float seed_y;

void boundaryFill4(int x,int,float*fc,float*bc);
void display(){
    // glClearColor(0.0,0.0,0.0,0.0);
    glLineWidth(1.7f);
    // glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(0.0,0.0,1.0);
    glBegin(GL_LINES);
        glVertex2f(halfWidth,0);
        glVertex2f(-halfWidth,0);
        glVertex2f(0,halfHeight);
        glVertex2f(0,-halfHeight);
    glEnd();//stored in frame buffer
    glFlush();//flushing from frame buffer to display
  }
int start=1;
void draw_line(){
    //  glClearColor(0.0,0.0,0.0,0.0);
    glLineWidth(1.7f);
    // glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(0.0,0.0,1.0);
    glBegin(GL_LINES);
        glVertex2f(vertx[start-1],verty[start-1]);
        glVertex2f(vertx[start],verty[start]);
        start++;
    glEnd();
    glFlush();
}

void callback_mouse_button(int button,int state,int x,int y){
    static int count=1;
    
    int adjusted_x = x - halfWidth;
    int adjusted_y = -(y - halfHeight);
    if(button==GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        cout<<adjusted_x<< ","<<adjusted_y<<endl;
        if(vertx.size()+verty.size()==0){
            vertx.push_back(adjusted_x);
            verty.push_back(adjusted_y);
        }
        else if(vertx.size()+verty.size()>=2){
            vertx.push_back(adjusted_x);
            verty.push_back(adjusted_y);
            draw_line();
        }
    }
    else if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){
        if(count==1){
        glBegin(GL_LINES);
        glVertex2f(vertx[0],verty[0]);
        glVertex2f(vertx[vertx.size()-1],verty[verty.size()-1]);
        glEnd();
        glFlush();
        count+=1;
        }
        else if(count==2){
            float bc[] = {0,0,1};
            float fc[] = {1,1,0};
            seed_x=adjusted_x;
            seed_y=adjusted_y;
            // cout<<"seed "<<seed_x<<" ,"<<seed_y;
            boundaryFill4(seed_x,seed_y,fc,bc);
        }
    }
    
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(10, 10);
    int main_window=glutCreateWindow("Fiiling Algorithms");
    glutMouseFunc(callback_mouse_button);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    halfHeight = glutGet(GLUT_WINDOW_HEIGHT)/2;
    halfWidth = glutGet(GLUT_WINDOW_WIDTH)/2;
    glViewport(0, 0, halfWidth*2, halfHeight*2);
    gluOrtho2D(-halfWidth, halfWidth, -halfHeight, halfHeight);

    glutDisplayFunc(display);
    glutMainLoop();

}
void boundaryFill4(int x,int y,float *fc,float *bc){
    float color[3];
    glReadPixels(x+halfWidth,y+halfWidth,1,1,GL_RGB,GL_FLOAT,color);
    if((color[0]!=bc[0] || color[1]!=bc[1] || color[2]!=bc[2])&&(
    color[0]!=fc[0] || color[1]!=fc[1] || color[2]!=fc[2])){
    // glColor3f(fc[0],fc[1],fc[2]);
    // glBegin(GL_POINTS);
    // glPointSize(2.7f);
    // glVertex2i(x,y);
    glRasterPos2i(x,y);
    glDrawPixels(1,1,GL_RGB,GL_FLOAT,fc);
    // glEnd();
    glFlush();
    boundaryFill4(x+1,y,fc,bc);
    boundaryFill4(x-1,y,fc,bc);
    boundaryFill4(x,y+1,fc,bc);
    boundaryFill4(x,y-1,fc,bc);
}
}
