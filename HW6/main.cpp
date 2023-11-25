#include <GL/glut.h>
#include <iostream>
#include <cmath>

// Matriks 3x3
float matrix[3][3] = {
    {1.0f, 0.0f, 0.0f},
    {0.0f, 1.0f, 0.0f},
    {0.0f, 0.0f, 1.0f}
};

// Fungsi untuk menampilkan matriks 3x3
void displayMatrix() {
    std::cout << "Matrix 3x3:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Fungsi untuk membuat matriks translasi
void translate(float tx, float ty) {
    float translateMatrix[3][3] = {
        {1.0f, 0.0f, tx},
        {0.0f, 1.0f, ty},
        {0.0f, 0.0f, 1.0f}
    };

    // Kombinasikan dengan matriks yang ada
    // Anda juga bisa menggunakan operasi lain seperti perkalian
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            float sum = 0.0f;
            for (int k = 0; k < 3; ++k) {
                sum += matrix[i][k] * translateMatrix[k][j];
            }
            matrix[i][j] = sum;
        }
    }
}

// Fungsi untuk membuat matriks rotasi
void rotate(float angle) {
    float cosA = cos(angle);
    float sinA = sin(angle);

    float rotateMatrix[3][3] = {
        {cosA, -sinA, 0.0f},
        {sinA, cosA, 0.0f},
        {0.0f, 0.0f, 1.0f}
    };

    // Kombinasikan dengan matriks yang ada
    // Anda juga bisa menggunakan operasi lain seperti perkalian
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            float sum = 0.0f;
            for (int k = 0; k < 3; ++k) {
                sum += matrix[i][k] * rotateMatrix[k][j];
            }
            matrix[i][j] = sum;
        }
    }
}

// Fungsi untuk membuat matriks skala
void scale(float sx, float sy) {
    float scaleMatrix[3][3] = {
        {sx, 0.0f, 0.0f},
        {0.0f, sy, 0.0f},
        {0.0f, 0.0f, 1.0f}
    };

    // Kombinasikan dengan matriks yang ada
    // Anda juga bisa menggunakan operasi lain seperti perkalian
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            float sum = 0.0f;
            for (int k = 0; k < 3; ++k) {
                sum += matrix[i][k] * scaleMatrix[k][j];
            }
            matrix[i][j] = sum;
        }
    }
}

// Fungsi display
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Tampilkan matriks 3x3
    displayMatrix();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Matrix Transform");
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(display);

    float tx, ty;
    float angle;
    float sx, sy;

    std::cout << "Masukkan nilai translasi (tx ty): ";
    std::cin >> tx >> ty;
    translate(tx, ty);

    std::cout << "Masukkan nilai rotasi (derajat): ";
    std::cin >> angle;
    angle = angle * (M_PI / 180.0f); // Ubah ke radian
    rotate(angle);

    std::cout << "Masukkan nilai skala (sx sy): ";
    std::cin >> sx >> sy;
    scale(sx, sy);

    glutMainLoop();
    return 0;
}
