#include <iostream>

using namespace std;

int main()
{
    double x[100],y[100],garis1[100],garis2[100],t[100],b[100],r[100],l[100];
    int i,j;

    x[0] = 1;
    y[0] = 1;
    x[1] = 4;
    y[1] = 5;

    cout << "Masukkan nilai pada garis 1 :"<<endl;
    cout << "   Nilai titik A :";
    for (i = 0; i < 2; i++)
    {
        cin >> garis1[i];
    }
    cout << "   Nilai titik B :";
    for (i=2; i < 4; i++)
    {
        cin >> garis1[i];
    }
    cout << endl;
    cout << "Masukkan nilai pada garis 2 :"<<endl;
    cout << "   Nilai titik C :";
    for (j = 0; j < 2; j++)
    {
        cin >> garis2[j];
    }
    cout << "   Nilai titik D :";
    for (j = 2; j < 4; j++)
    {
        cin >> garis2[j];
    }
    cout << endl;

    cout << "Region garis 1 "<<endl;
    //x1 = [0] , y1 = [1] , x2 = [2] , y2 = [3]
    //tbrl [0] = nilai region titik A , tbrl [1] = nilai region titik B , tbrl [2] = nilai region titik C , tbrl [3] = nilai region titik D
    //Region titik A
    if (garis1[1] <= y[1])
    {
        t[0] = 0;
    }else if (garis1[1] > y[1])
    {
        t[0]=1;
    }

    if (garis1[1] < y[0])
    {
        b[0] = 1;
    }else if (garis1[1] >= y[0])
    {
        b[0]=0;
    }

    if (garis1[0] > x[1])
    {
        r[0]=1;
    }else if (garis1[0] <= x[1])
    {
        r[0]=0;
    }

    if (garis1[0] < x[0])
    {
        l[0]=1;
    }else if (garis1[0] >= x[0])
    {
        l[0]=0;
    }
    cout << "   Nilai region titik A:";
    cout << t[0] << b[0] << r[0] << l[0] <<endl;
    //Region titik B
    if (garis1[3] <= y[1])
    {
        t[1] = 0;
    }else if (garis1[3] > y[1])
    {
        t[1]=1;
    }

    if (garis1[3] < y[0])
    {
        b[1] = 1;
    }else if (garis1[3] >= y[0])
    {
        b[1]=0;
    }

    if (garis1[2] > x[1])
    {
        r[1]=1;
    }else if (garis1[2] <= x[1])
    {
        r[1]=0;
    }

    if (garis1[2] < x[0])
    {
        l[1]=1;
    }else if (garis1[2] >= x[0])
    {
        l[1]=0;
    }
    cout << "   Nilai region titik B:";

    cout << t[1] << b[1] << r[1] << l[1]<<endl;
    cout << "Region garis 2 "<<endl;
    //Region titik C
    if (garis2[1] <= y[1])
    {
        t[2] = 0;
    }else if (garis2[1] > y[1])
    {
        t[2]=1;
    }

    if (garis2[1] < y[0])
    {
        b[2] = 1;
    }else if (garis2[1] >= y[0])
    {
        b[2]=0;
    }

    if (garis2[0] > x[1])
    {
        r[2]=1;
    }else if (garis2[0] <= x[1])
    {
        r[2]=0;
    }

    if (garis2[0] < x[0])
    {
        l[2]=1;
    }else if (garis2[0] >= x[0])
    {
        l[2]=0;
    }
    cout << "   Nilai region titik C:";
    cout << t[2] << b[2] << r[2] << l[2]<<endl;
    //Region titik D
    if (garis2[3] <= y[1])
    {
        t[3] = 0;
    }else if (garis2[3] > y[1])
    {
        t[3]=1;
    }

    if (garis2[3] < y[0])
    {
        b[3] = 1;
    }else if (garis2[3] >= y[0])
    {
        b[3]=0;
    }

    if (garis2[2] > x[1])
    {
        r[3]=1;
    }else if (garis2[2] <= x[1])
    {
        r[3]=0;
    }

    if (garis2[2] < x[0])
    {
        l[3]=1;
    }else if (garis2[2] >= x[0])
    {
        l[3]=0;
    }
    cout << "   Nilai region titik D:";
    cout << t[3] << b[3] << r[3] << l[3];
    cout << endl;

    cout << "Mencari titik potong"<<endl;
    double xp1[100], xp2[100], yp1[100], yp2[100],m1,m2;
    cout << "Garis 1" << endl;
    //Garis 1
    //titik potong A
    m1=(garis1[3]-garis1[1])/(garis1[2]-garis1[0]);
    cout << "   Titik Potong A :" << endl;
    if(t[0]==1)
    {
        xp2[0] = garis1[0] + (y[1] - garis1[1]) / m1;
        cout << "   ("<<xp2[0] << "," << y[1] << ")" << endl;

    }
    if(b[0]==1)
    {
        xp1[0] = garis1[0] + (y[0] - garis1[1]) / m1;
        cout << "   ("<<xp1[0] << "," << y[0] << ")" << endl;
    }
    if(r[0]==1)
    {
        yp2[0] = garis1[1] + m1 * (x[1] - garis1[0]);
        cout << "   ("<<x[1] << "," << yp2[0] << ")" << endl;
    }
    if(l[0]==1)
    {
        yp1[0] = garis1[1] + m1 * (x[0] - garis1[0]);
        cout << "   ("<<x[0] << "," << yp1[0] << ")" << endl;
    }
    cout << endl;
    //Titik potong B
    cout << "   Titik Potong B :" << endl;
    if(t[1]==1)
    {
        xp2[1] = garis1[2] + (y[1] - garis1[3]) / m1;
        cout << "   ("<<xp2[1] << "," << y[1] << ")" << endl;

    }
    if(b[1]==1)
    {
        xp1[1] = garis1[2] + (y[0] - garis1[3]) / m1;
        cout << "   ("<<xp1[1] << "," << y[0] << ")" << endl;
    }
    if(r[1]==1)
    {
        yp2[1] = garis1[3] + m1 * (x[1] - garis1[2]);
        cout << "   ("<<x[1] << "," << yp2[1] << ")" << endl;
    }
    if(l[1]==1)
    {
        yp1[1] = garis1[3] + m1 * (x[0] - garis1[2]);
        cout << "   ("<<x[0] << "," << yp1[1] << ")" << endl;
    }
    cout << endl;

    cout << "Garis 2"<<endl;
    m2=(garis2[3]-garis2[1])/(garis2[2]-garis2[0]);
    cout << "   Titik potong C:"<<endl;
    //Titik potong C
    if(t[2]==1)
    {
        xp2[2] = garis2[0] + (y[1] - garis2[1]) / m2;
        cout << "   ("<<xp2[2] << "," << y[1] << ")" << endl;

    }
    if(b[2]==1)
    {
        xp1[2] = garis2[0] + (y[0] - garis2[1]) / m2;
        cout << "   ("<<xp1[2] << "," << y[0] << ")" << endl;
    }
    if(r[2]==1)
    {
        yp2[2] = garis2[1] + m2 * (x[1] - garis2[0]);
        cout << "   ("<<x[1] << "," << yp2[2] << ")" << endl;
    }
    if(l[2]==1)
    {
        yp1[2] = garis2[1] + m2 * (x[0] - garis2[0]);
        cout << "   ("<<x[0] << "," << yp1[2] << ")" << endl;
    }
    cout << endl;
    cout << "   Titik potong D:"<<endl;
    //Titik potong D
    if(t[3]==1)
    {
        xp2[3] = garis2[2] + (y[1] - garis2[3]) / m2;
        cout << "   ("<<xp2[3] << "," << y[1] << ")" << endl;

    }
    if(b[3]==1)
    {
        xp1[3] = garis2[2] + (y[0] - garis2[3]) / m2;
        cout << "   ("<<xp1[3] << "," << y[0] << ")" << endl;
    }
    if(r[3]==1)
    {
        yp2[3] = garis2[3] + m2 * (x[1] - garis2[2]);
        cout << "   ("<<x[1] << "," << yp2[3] << ")" << endl;
    }
    if(l[3]==1)
    {
        yp1[3] = garis2[3] + m2 * (x[0] - garis2[2]);
        cout << "   ("<<x[0] << "," << yp1[3] << ")" << endl;
    }
    cout << endl;

    cout << " Menentukan titik potong yang masuk dalam viewport "<<endl;
    cout << "Garis 1"<<endl;
    //Seleksi titik potong A
    if (xp1[0] > x[0] && xp1[0] <= x[1])
    {
        cout << "   ("<< xp1[0] << "," << y[0] << ")" << endl;
    }
    if (yp1[0] > y[0] && yp1[0] <= y[1])
    {
        cout << "   ("<< yp1[0] << "," << x[0]<< ")" << endl;
    }
    if (xp2[0] > x[0] && xp2[0] <= x[1])
    {
        cout << "   ("<< xp2[0] << "," << y[1]<< ")" << endl;
    }
    if (yp2[0] > y[0] && yp2[0] <= y[1])
    {
        cout << "   ("<< yp2[0] << "," << x[1]<< ")" << endl;
    }
    //Seleksi titik potong B
    if (xp1[1] > x[0] && xp1[1] <= x[1])
    {
        cout << "   ("<< xp1[1] << "," << y[0] << ")" << endl;
    }
    if (yp1[1] > y[0] && yp1[1] <= y[1])
    {
        cout << "   ("<< yp1[1] << "," << x[0]<< ")" << endl;
    }
    if (xp2[1] > x[0] && xp2[1] <= x[1])
    {
        cout << "   ("<< xp2[1] << "," << y[1]<< ")" << endl;
    }
    if (yp2[1] > y[0] && yp2[1] <= y[1])
    {
        cout << "   ("<< yp2[1] << "," << x[1]<< ")" << endl;
    }
    cout << endl;

    cout << "Garis 2" << endl;
    //Seleksi titik potong C
    if (xp1[2] > x[0] && xp1[2] <= x[1])
    {
        cout << "   ("<< xp1[2] << "," << y[0] << ")" << endl;
    }
    if (yp1[2] > y[0] && yp1[2] <= y[1])
    {
        cout << "   ("<< yp1[2] << "," << x[0]<< ")" << endl;
    }
    if (xp2[2] > x[0] && xp2[2] <= x[1])
    {
        cout << "   ("<< xp2[2] << "," << y[1]<< ")" << endl;
    }
    if (yp2[2] > y[0] && yp2[2] <= y[1])
    {
        cout << "   ("<< yp2[2] << "," << x[1]<< ")" << endl;
    }
    //Seleksi titik potong D
    if (xp1[3] > x[0] && xp1[3] <= x[1])
    {
        cout << "   ("<< xp1[3] << "," << y[0] << ")" << endl;
    }
    if (yp1[3] > y[0] && yp1[3] <= y[1])
    {
        cout << "   ("<< yp1[3] << "," << x[0]<< ")" << endl;
    }
    if (xp2[3] > x[0] && xp2[3] <= x[1])
    {
        cout << "   ("<< xp2[3] << "," << y[1]<< ")" << endl;
    }
    if (yp2[3] > y[0] && yp2[3] <= y[1])
    {
        cout << "   ("<< yp2[3] << "," << x[1]<< ")" << endl;
    }
    return 0;
}
