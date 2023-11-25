#include <GL/glut.h>
#include <iostream>
#include <cmath>

// Matriks 3x3
float matrix[3][3] = {
    {1.0f, 0.0f, 0.0f},
    {0.0f, 1.0f, 0.0f},
    {0.0f, 0.0f, 1.0f}
};

// Titik awal A dan B
float pointA[3] = {1.0f, 3.0f, 1.0f};
float pointB[3] = {7.0f, 1.0f, 1.0f};

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

// Fungsi untuk membuat matriks mirror/refleksi
void mirror(bool x_axis, bool y_axis) {
    if (x_axis) {
        matrix[0][0] *= -1;
    }
    if (y_axis) {
        matrix[1][1] *= -1;
    }
}

// Fungsi display
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Tampilkan matriks 3x3
    displayMatrix();

    // Lakukan transformasi terhadap titik A
    float transformedPointA[3];
    for (int i = 0; i < 3; ++i) {
        transformedPointA[i] = matrix[i][0] * pointA[0] + matrix[i][1] * pointA[1] + matrix[i][2] * pointA[2];
    }

    // Lakukan transformasi terhadap titik B
    float transformedPointB[3];
    for (int i = 0; i < 3; ++i) {
        transformedPointB[i] = matrix[i][0] * pointB[0] + matrix[i][1] * pointB[1] + matrix[i][2] * pointB[2];
    }

    // Tampilkan hasil transformasi titik A
    std::cout << "Titik Awal A (" << pointA[0] << ", " << pointA[1] << ") setelah transformasi: ";
    std::cout << "(" << transformedPointA[0] << ", " << transformedPointA[1] << ")" << std::endl;

    // Tampilkan hasil transformasi titik B
    std::cout << "Titik Awal B (" << pointB[0] << ", " << pointB[1] << ") setelah transformasi: ";
    std::cout << "(" << transformedPointB[0] << ", " << transformedPointB[1] << ")" << std::endl;

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Transformasi Matrix");
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(display);

    // Input translasi, rotasi, skala, mirror/refleksi
    float tx, ty;
    float angle;
    float sx, sy;
    bool mirrorX, mirrorY;

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

    std::cout << "Apakah ingin mirror/refleksi pada sumbu X? (1/0): ";
    std::cin >> mirrorX;
    std::cout << "Apakah ingin mirror/refleksi pada sumbu Y? (1/0): ";
    std::cin >> mirrorY;
    mirror(mirrorX, mirrorY);

    glutMainLoop();
    return 0;
}

