#include <iostream>
#include <GL/freeglut.h>
#include <cmath>
#include <vector>

struct Point {
    int x, y;
};

struct Color {
    float r, g, b;
};

std::vector<std::pair<Point, Point>> lines;
Point p1 = {-1, -1};
Point p2 = {-1, -1};

enum LineAlgorithm {
    ALGORITHM_SYMMETRIC,
    ALGORITHM_SIMPLE,
    ALGORITHM_BRESENHAM
};

LineAlgorithm selectedAlgorithm = ALGORITHM_SYMMETRIC;
Color lineColor = {1.0, 1.0, 1.0};  // Default color: white

bool dashedPattern = false;
bool dottedPattern = false;
bool solidPattern = true; // Default: Solid pattern

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(-300, 300, -300, 300);
}

void drawPoint(int x, int y) {
    std::cout << "(" << x << ", " << y << ") ";
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void drawSolidLine(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}
void patternMenu(int item) {
    dashedPattern = (item == 1);
    dottedPattern = (item == 2);
    solidPattern = (item == 3);
    glutPostRedisplay();
}
void symmetricDDALine(int x1, int y1, int x2, int y2) {

    glColor3f(lineColor.r, lineColor.g, lineColor.b);
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xIncrement = float(dx) / steps;
    float yIncrement = float(dy) / steps;

    float x = x1, y = y1;
    for (int i = 0; i <= steps; ++i) {
        drawPoint(round(x), round(y));
        x += xIncrement;
        y += yIncrement;
    }

}

void simpleDDALine(int x1, int y1, int x2, int y2) {

     glColor3f(lineColor.r, lineColor.g, lineColor.b);
    int dx = x2 - x1;
    int dy = y2 - y1;
    float steps = std::max(std::abs(dx), std::abs(dy));
    float xIncrement = float(dx) / steps;
    float yIncrement = float(dy) / steps;

    float x = x1, y = y1;
    for (int i = 0; i <= steps; ++i) {
        drawPoint(round(x), round(y));
        x += xIncrement;
        y += yIncrement;
    }
}

void bresenhamLine(int x1, int y1, int x2, int y2) {

     glColor3f(lineColor.r, lineColor.g, lineColor.b);
      int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        drawPoint(x1, y1);
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 < dx) { err += dx; y1 += sy; }
    }
}
int selectedThickness = 1;

void drawLines() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw X and Y axes
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_LINES);
    glVertex2i(-300, 0);
    glVertex2i(300, 0);
    glVertex2i(0, -300);
    glVertex2i(0, 300);
    glEnd();

    glColor3f(lineColor.r, lineColor.g, lineColor.b);

    for (const auto &line : lines) {
        // Calculate the angle of the line
        float angle = atan2(line.second.y - line.first.y, line.second.x - line.first.x);
        float halfLineWidth = (selectedThickness - 1) / 2.0f;

        // Draw multiple lines to simulate thickness
        for (int i = -halfLineWidth; i <= halfLineWidth; ++i) {
            float offsetX = i * sin(angle);
            float offsetY = -i * cos(angle);
            glBegin(GL_LINE_STRIP);
            glVertex2f(line.first.x + offsetX, line.first.y + offsetY);
            glVertex2f(line.second.x + offsetX, line.second.y + offsetY);
            glEnd();
        }

        // Draw points along the line
        int dx = abs(line.second.x - line.first.x);
        int dy = abs(line.second.y - line.first.y);
        int steps = std::max(dx, dy) + 1;
        float xIncrement = float(line.second.x - line.first.x) / steps;
        float yIncrement = float(line.second.y - line.first.y) / steps;

        float x = line.first.x, y = line.first.y;
        for (int i = 0; i < steps; ++i) {
            drawPoint(round(x), round(y));
            x += xIncrement;
            y += yIncrement;
        }
    }

    glFlush();
}



void mouse(int button, int state, int x, int y) {
    if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON) {
        if (p1.x == -1) {
            p1.x = x - 300;
            p1.y = 300 - y;
        } else if (p2.x == -1) {
            p2.x = x - 300;
            p2.y = 300 - y;

            lines.push_back(std::make_pair(p1, p2)); // Add the new line
            drawLines();

            p1.x = p1.y = p2.x = p2.y = -1;
        }
    }
}
void colorSubMenu(int item) {
    switch (item) {
        case 1:
            lineColor = {1.0, 0.0, 0.0};  // Red
            break;
        case 2:
            lineColor = {0.0, 1.0, 0.0};  // Green
            break;
        case 3:
            lineColor = {0.0, 0.0, 1.0};  // Blue
            break;
        default:
            break;
    }
    glutPostRedisplay(); 
}

void menu(int item) {
    switch (item) {
        case 0:
            break;  
        case 1:
            selectedAlgorithm = ALGORITHM_SYMMETRIC;
            break;
        case 2:
            selectedAlgorithm = ALGORITHM_SIMPLE;
            break;
        case 3:
            selectedAlgorithm = ALGORITHM_BRESENHAM;
            break;
        default:
            break;
    }
}


void thicknessMenu(int item) {
    switch (item) {
        case 1:
            selectedThickness = 1;
            break;
        case 2:
            selectedThickness = 2;
            break;
        case 3:
            selectedThickness = 3;
            break;
        default:
            selectedThickness = 1; // Set a default value
            break;
    }
    glutPostRedisplay(); 
}

void createMenu() {
    int colorSubMenuId = glutCreateMenu(colorSubMenu);
    glutAddMenuEntry("Red", 1);
    glutAddMenuEntry("Green", 2);
    glutAddMenuEntry("Blue", 3);

    int algorithmSubMenuId = glutCreateMenu(menu);
    glutAddMenuEntry("Symmetric DDA", 1);
    glutAddMenuEntry("Simple DDA", 2);
    glutAddMenuEntry("Bresenham", 3);

    int thicknessSubMenuId = glutCreateMenu(thicknessMenu); // Create the thickness submenu
    glutAddMenuEntry("1", 1); // Line thickness: 1
    glutAddMenuEntry("2", 2); // Line thickness: 2
    glutAddMenuEntry("3", 3); // Line thickness: 3

     int patternSubMenuId = glutCreateMenu(patternMenu); // Create the pattern submenu
    glutAddMenuEntry("Dashed", 1);
    glutAddMenuEntry("Dotted", 2);
    glutAddMenuEntry("Solid", 3);

    glutCreateMenu(menu);
    glutAddSubMenu("Select Line Color", colorSubMenuId);
    glutAddSubMenu("Select Line Algorithm", algorithmSubMenuId);
    glutAddSubMenu("Select Line Thickness", thicknessSubMenuId); // Add the thickness submenu
    glutAddSubMenu("Select Line Pattern", patternSubMenuId); // Add the pattern submenu
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Line Drawing Algorithms");
    init();
    glutDisplayFunc(drawLines);
    glutMouseFunc(mouse);
    createMenu(); // Create the right-click menu
    glutMainLoop();
    return 0;
}