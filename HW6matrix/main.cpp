#include <iostream>
#include <cmath>

class Matrix {
public:
    float matrix[3][3];

    // Konstruktor untuk inisialisasi matriks identitas
    Matrix() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (i == j) {
                    matrix[i][j] = 1.0f;
                } else {
                    matrix[i][j] = 0.0f;
                }
            }
        }
    }

    // Fungsi untuk menampilkan matriks
    void displayMatrix() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    // Fungsi untuk membuat matriks translasi
    static Matrix translate(float tx, float ty) {
        Matrix translationMatrix;

        translationMatrix.matrix[0][2] = tx;
        translationMatrix.matrix[1][2] = ty;

        return translationMatrix;
    }

    // Fungsi untuk membuat matriks rotasi
    static Matrix rotate(float angle) {
        Matrix rotationMatrix;

        float cosA = cos(angle);
        float sinA = sin(angle);

        rotationMatrix.matrix[0][0] = cosA;
        rotationMatrix.matrix[0][1] = -sinA;
        rotationMatrix.matrix[1][0] = sinA;
        rotationMatrix.matrix[1][1] = cosA;

        return rotationMatrix;
    }

    // Fungsi untuk membuat matriks skala
    static Matrix scale(float sx, float sy) {
        Matrix scalingMatrix;

        scalingMatrix.matrix[0][0] = sx;
        scalingMatrix.matrix[1][1] = sy;

        return scalingMatrix;
    }
};

int main() {
    // Misalkan kita ingin translasi sebesar (2, 3)
    float translationX = 2.0f;
    float translationY = 3.0f;

    // Membuat matriks translasi
    Matrix translationMatrix = Matrix::translate(translationX, translationY);

    // Misalkan kita ingin rotasi sebesar 45 derajat
    float rotationAngle = 45.0f * (M_PI / 180.0f); // Ubah ke radian
    Matrix rotationMatrix = Matrix::rotate(rotationAngle);

    // Misalkan kita ingin skala sebesar (2, 2)
    float scaleX = 2.0f;
    float scaleY = 2.0f;
    Matrix scalingMatrix = Matrix::scale(scaleX, scaleY);

    // Menampilkan hasil matriks
    std::cout << "Matrix Translasi:" << std::endl;
    translationMatrix.displayMatrix();

    std::cout << "\nMatrix Rotasi:" << std::endl;
    rotationMatrix.displayMatrix();

    std::cout << "\nMatrix Skala:" << std::endl;
    scalingMatrix.displayMatrix();

    return 0;
}
