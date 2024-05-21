#include <iostream>

using namespace std;

int main()
{
    // variable untuk menampung data, cari dan ketemu
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;
    // perulangan untuk mencari nilai dengan mencocokan data dengan nilai cari
    for (i = 0; i < n; i++)
    {
        if (data[i] == cari)
        {
            ketemu = true;
            break;
        }
    }
    // menampilkan data
    cout << " Program Sequential Search" << endl;
    cout << " data : {9,4,1,7,5,12,4,13,4,10}" << endl;
    // percabangan ketika angka di temukan pada indeks keberapa
    if (ketemu)
    {
        cout << "\nAngka " << cari << " ditemukan pada indeks ke-" << i << endl;
    }
    else
    {
        cout << "\nAngka " << cari << " tidak ditemukan" << endl;
    }
    return 0;
}