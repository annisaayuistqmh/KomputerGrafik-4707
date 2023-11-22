#include <GL/glut.h>
#include <glm/glm.hpp>
#include <iostream>

// Titik A dan B
glm::vec2 A(8, 1);
glm::vec2 B(7, 3);

// Fungsi untuk melakukan translasi
void translate(glm::vec2& point, float tx, float ty) {
    glm::mat3 translateMatrix = {
        {1, 0, 0},
        {0, 1, 0},
        {tx, ty, 1}
    };
    glm::vec3 result = translateMatrix * glm::vec3(point, 1);
    point.x = result.x;
    point.y = result.y;
}

// Fungsi untuk melakukan rotasi
void rotate(glm::vec2& point, float angle) {
    float rad = glm::radians(angle);
    glm::mat3 rotateMatrix = {
        {cos(rad), -sin(rad), 0},
        {sin(rad), cos(rad), 0},
        {0, 0, 1}
    };
    glm::vec3 result = rotateMatrix * glm::vec3(point, 1);
    point.x = result.x;
    point.y = result.y;
}

// Fungsi untuk melakukan scaling
void scale(glm::vec2& point, float sx, float sy) {
    glm::mat3 scaleMatrix = {
        {sx, 0, 0},
        {0, sy, 0},
        {0, 0, 1}
    };
    glm::vec3 result = scaleMatrix * glm::vec3(point, 1);
    point.x = result.x;
    point.y = result.y;
}

// Fungsi untuk menggambar titik
void drawPoint(glm::vec2 point) {
    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2f(point.x, point.y);
    glEnd();
}

// Fungsi untuk merender
void renderScene() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    // Gambar titik asli
    glColor3f(1.0, 1.0, 1.0);
    drawPoint(A);
    drawPoint(B);

    // Lakukan transformasi pada titik A dan B
    translate(A, 2, 2); // translasi
    rotate(B, 45);      // rotasi
    scale(A, 1.5, 1.5); // scaling

    // Gambar titik setelah transformasi
    glColor3f(1.0, 0.0, 0.0);
    drawPoint(A);
    drawPoint(B);

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Transformasi Titik OpenGL");

    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(-10, 10, -10, 10);

    glutDisplayFunc(renderScene);

    glutMainLoop();
    return 0;
}

