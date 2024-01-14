#include <iostream>
#include <cmath>
#include <limits>

using namespace std;
//data 
double matrix [100][100];
double pAwal [100];
double pAkhir [100];
double temp = 0 ;
double hasil;
int i, j;
double derajat;
double nilaiSin,nilaiCos,radian;
char akhir, sumbu;


//1. Translasi
void matrixTranslasi3D(int xAwal, int yAwal, int zAwal, int xt, int yt, int zt) 
{

    cout << "--------------------------------Matrix Translasi 3D--------------------------------" << endl;

    // Define the 4x4 translation matrix
    int matrix[4][4] = 
    {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {xt, yt, zt, 1}
    };

    // Define the initial coordinates as a column vector
    int pAwal[4] = {xAwal, yAwal, zAwal, 1};

    // Perform matrix multiplication
    int pAkhir[4];
    for (int j = 0; j < 4; j++) {
        pAkhir[j] = 0;
        for (int i = 0; i < 4; i++) {
            pAkhir[j] += matrix[i][j] * pAwal[i];
        }
    }
    cout << "\nMatrix Koordinat Translasi 3D:" << endl;

    // Print the resulting translated coordinates
    for (int j = 0; j < 3; j++) {
        cout <<pAkhir[j] << " ";
    }

    cout << endl;
}

//2. Skala
void matrixSkala3D (int xAwal, int yAwal, int zAwal, int xs, int ys, int zs)
{

    cout << "--------------- Hasil ---------------" << endl;

    // Define the 4x4 translation matrix
    int matrix[4][4] = 
    {
        {xs, 0, 0, 0},
        {0, ys, 0, 0},
        {0, 0, zs, 0},
        {0, 0, 0, 1}
    };

    // Define the initial coordinates as a column vector
    int pAwal[4] = {xAwal, yAwal, zAwal, 1};

    // Perform matrix multiplication to apply scaling
    int pAkhir[4];
    for (int j = 0; j < 4; j++) {
        pAkhir[j] = 0;
        for (int i = 0; i < 4; i++) {
            pAkhir[j] += matrix[i][j] * pAwal[i];
        }
    }

    // Print the resulting scaled coordinates
    cout << "\nMatrix Koordinat Skala 3D:" << endl;
    for (int j = 0; j < 3; j++) {
        cout << pAkhir[j] << " ";
    }

    cout << endl;
}

//3. Rotasi
void matrixRotasi3D (int xAwal, int yAwal, int zAwal, double derajat)
{
    do{
        cout << "Masukkan sumbu : ";
        cin >> sumbu;

        cout << "--------------- Hasil ---------------" << endl;

        // Define sin cos
        radian = derajat * M_PI / 180;
        nilaiSin = sin(radian);
        nilaiCos = cos(radian);

        // Define the initial coordinates as a column vector
        int pAwal[4] = {xAwal, yAwal, zAwal, 1};

        // Define the 4x4 translation matrix
        int matrix[4][4] = {
            {1, 0, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 1}
        };
        
        // Matrix terhadap sumbu yang ditentukan
        switch (sumbu) {
            case 'x':
                matrix[1][1] = nilaiCos;
                matrix[1][2] = nilaiSin;
                matrix[2][1] = -nilaiSin;
                matrix[2][2] = nilaiCos;
                break;
            case 'y':
                matrix[0][0] = nilaiCos;
                matrix[0][2] = -nilaiSin;
                matrix[2][0] = nilaiSin;
                matrix[2][2] = nilaiCos;
                break;
            case 'z':
                matrix[0][0] = nilaiCos;
                matrix[0][1] = nilaiSin;
                matrix[1][0] = -nilaiSin;
                matrix[1][1] = nilaiCos;
                break;

            default:
                cout << "Pilihan Tidak Valid!!!"<<endl; 
                break;
        }

        /// Perform matrix multiplication to apply rotation
        int pAkhir[4];
        for (int j = 0; j < 4; j++) {
            pAkhir[j] = 0;
            for (int i = 0; i < 4; i++) {
                pAkhir[j] += matrix[i][j] * pAwal[i];
            }
        }

        // Print the resulting rotated coordinates
        cout << "Koordinat awal: " << endl;
        for (int i = 0; i < 3; i++) {
            cout << pAwal[i] << " ";
        }
        cout << endl;
        cout << "Koordinat akhir: " << endl;
        for (int i = 0; i < 3; i++) {
            cout << pAkhir[i] << " ";
        }
        cout << endl;
        
        cout << "\nIngin Mencoba Sumbu Lain? (Y/T) :" << endl;
        cin >> akhir;

    }
    while (akhir == 'Y' || akhir == 'y');
    if (akhir == 'T' || akhir == 't') {
        return;
    }

    //matrixRotasi3D(xAwal, yAwal, zAwal, derajat);
}


int main ()
{    
    int pilih;
    char akhir;
    int x,y,z;
    int xt,yt,zt;
    int xs,ys,zs;
    double derajat;

    do{
        cout << "~~~ Transformasi Matrix 3D ~~~\n"<<endl;
        cout << "Pilih 3 rumus matrix berikut \n1. Matrix Translasi\n2. Matrix Skala\n3. Matrix Rotasi"<<endl;
        cin >> pilih;

        switch (pilih)
        {
            case 1:
                cout <<"---------- Matrix Translasi 3D ----------"<<endl;

                cout << "Masukkan koordinat Awal ( 3 titik ): ";
                cin >> x;
                cin >> y;
                cin >> z;

                cout << "Masukkan nilai t : ";
                cin >> xt;
                cin >> yt;
                cin >> zt;

                matrixTranslasi3D(x, y, z, xt, yt, zt);
                break;
            
            case 2:
                cout <<"---------- Matrix Skala 3D ----------"<<endl;

                cout << "Masukkan koordinat Awal ( 3 titik ): ";
                cin >> x;
                cin >> y;
                cin >> z;

                cout << "Masukkan nilai Skala : ";
                cin >> xs;
                cin >> ys;
                cin >> zs;

                matrixSkala3D(x, y, z, xs, ys, zs);
                break;

            case 3:
                cout <<"---------- Matrix Rotasi 3D ----------"<<endl;

                cout << "Masukkan koordinat Awal ( 3 titik ): ";
                cin >> x;
                cin >> y;
                cin >> z;

                cout << "Masukkan nilai derajat : ";
                cin >> derajat;

                matrixRotasi3D(x, y, z, derajat);
                break;

            default:
                cout << "Pilihan Tidak Valid!!!"<<endl; 
                break;
        }
        

        cout << "\nUlang Program Transformasi 3D (Y/T) :" << endl;
        cin >> akhir;

    }
    while (akhir == 'Y' || akhir == 'y');
    return 0;    
}