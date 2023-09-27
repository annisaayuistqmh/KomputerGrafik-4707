/* Nama : Annisa Ayu Istiqomah
   NIM  : A11.2021.13718
   Kelas : A11.4707
*/

#include <iostream>
using namespace std;

int main (int argc, char** argv)
{
    int matriks_a[10][10],
    matriks_b[10][10],
    hasil[10][10],
    baris,
    kolom;

    cout << "Masukan Jumlah Baris = ";
    cin >> baris;
    cout << "Masukan Jumlah Kolom = ";
    cin >> kolom;

    cout << "Matriks A" << endl;

    for(int i = 0; i < baris; i++)
    {
        for(int j = 0; j < kolom;j ++)
        {
            cout << "Masukan elemen matriks A baris ke " << i << " kolom ke " << j << " = ";
            cin >> matriks_a[i][j];
        }
    }

    cout << "Matriks B" << endl;

    for(int i = 0; i < baris; i++)
    {
        for(int j = 0; j < kolom;j ++)
        {
            cout << "Masukan elemen matriks B baris ke " << i << " kolom ke " << j << " = ";
            cin >> matriks_b[i][j];
        }
    }

    // Penjumlahan Matriks
    cout << "Total penjumlahan " << endl;

    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            hasil[i][j] = matriks_a[i][j] + matriks_b[i][j];
            cout << " " << hasil[i][j] << " | ";
        }
        cout << endl;
    }

    // Pengurangan Matriks
    cout << "Total pengurangan " << endl;
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            hasil[i][j] = matriks_a[i][j] - matriks_b[i][j];
            cout << " " << hasil[i][j] << " | ";
        }
        cout << endl;
    }

    // Perkalian Matriks
    cout << "Total perkalian " << endl;
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            hasil[i][j]=0;
            for ( int k = 0; k < 2 ;k++)
            {
                hasil[i][j] += matriks_a[i][j] * matriks_b[i][j];
                cout << " " << hasil[i][j] << " | ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // Perkalian Skalar 1
    cout << "Total perkalian skalar 1 " << endl;
    int s = 2;
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            hasil[i][j] = matriks_a[i][j] * s;
            cout << " " << hasil[i][j] << " | ";
        }
        cout << endl;
    }

    // Perkalian Skalar 2
    cout << "Total perkalian skalar 2 " << endl;
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            hasil[i][j] = matriks_b[i][j] * s;
            cout << " " << hasil[i][j] << " | ";
        }
        cout << endl;
    }

    return 0;
}
