
#include<iostream>
#include<cmath>

using namespace std;

int main() {
    int x1, y1, x2, y2;

    // Input koordinat titik awal dan titik akhir
    cout << "Masukkan koordinat titik awal (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Masukkan koordinat titik akhir (x2 y2): ";
    cin >> x2 >> y2;

    // Menghitung perbedaan koordinat
    int dx = x2 - x1;
    int dy = y2 - y1;

    // Menentukan langkah iterasi (perbedaan maksimum antara x dan y)
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    // Menghitung perubahan x dan y setiap iterasi
    float deltaX = static_cast<float>(dx) / static_cast<float>(steps);
    float deltaY = static_cast<float>(dy) / static_cast<float>(steps);

    // Menampilkan titik-titik yang dilalui oleh garis
    cout << "Titik-titik yang dilalui oleh garis:" << endl;
    cout << "X\tY" << endl;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++) {
        cout << round(x) << "\t" << round(y) << endl;
        x += deltaX;
        y += deltaY;
    }

    return 0;
}