#include <GL/glut.h>
#include <iostream>
#include <cmath>

int numPolygons;
int sides;
float radius;
float separation;
float tiltAngle;

void drawPolygon(int sides, float radius, float tiltAngle) {
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_POLYGON);
    for (int i = 0; i < sides; i++) {
        float angle = 2.0 * M_PI * i / sides + tiltAngle;
        float x = radius * std::cos(angle);
        float y = radius * std::sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void drawConcentricPolygons(int numPolygons, int sides, float radius, float separation, float tiltAngle) {
    for (int i = 0; i < numPolygons; i++) {
        drawPolygon(sides, radius + i * separation, i * tiltAngle);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);

    drawConcentricPolygons(numPolygons, sides, radius, separation, tiltAngle);

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    std::cout << "Enter the number of polygons: ";
    std::cin >> numPolygons;

    std::cout << "Enter the number of sides for the polygons: ";
    std::cin >> sides;

    std::cout << "Enter the radius for the polygon: ";
    std::cin >> radius;

    std::cout << "Enter the separation for the polygons: ";
    std::cin >> separation;

    std::cout << "Enter the tilt angle for the polygons: ";
    std::cin >> tiltAngle;
    tiltAngle = tiltAngle * (M_PI / 180.0); // degrees to radians

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Concentric and Tilted Polygons");

    glutDisplayFunc(display);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-glutGet(GLUT_WINDOW_WIDTH) / 2, glutGet(GLUT_WINDOW_WIDTH) / 2, -glutGet(GLUT_WINDOW_HEIGHT) / 2, glutGet(GLUT_WINDOW_HEIGHT) / 2);

    glutMainLoop();

    return 0;
}