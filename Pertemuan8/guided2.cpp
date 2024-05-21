#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

// Mendeklarasikan variabel data
int dataArray[7] = {1,8,2,5,4,9,7};
int cari;

// Prosedur untuk mengurutkan data dalam dataArray
void selection_sort()
{
    int temp, min, i, j;
    for (i = 0; i < 7; i++)
    {
        min = i;
        // Perulangan untuk mengurutkan data dari terkecil hingga terbesar
        for (j = i + 1; j < 7; j++)
        {
            if (dataArray[j] < dataArray[min])
            {
                min = j;
            }
        }
        temp = dataArray[i];
        dataArray[i] = dataArray[min];
        dataArray[min] = temp;
    }
}

// Prosedur untuk mencari data
void binarySearch()
{
    // Mendeklarasikan variabel awal, akhir, dan tengah
    int awal, akhir, tengah;
    bool b_flag = false;
    awal = 0;
    akhir = 6;

    // Perulangan untuk mencari data
    while (!b_flag && awal <= akhir)
    {
        // Menghitung indeks tengah
        tengah = (awal + akhir) / 2;
        if (dataArray[tengah] == cari)
        {
            b_flag = true;
        }
        else if (dataArray[tengah] < cari)
        {
            awal = tengah + 1;
        }
        else
        {
            akhir = tengah - 1;
        }
    }
    // Menampilkan output jika angka yang dicari ditemukan
    if (b_flag)
    {
        cout << "\nData ditemukan pada indeks ke-" << tengah << endl;
    }else{
        cout << "\nDATA TIDAK DITEMUKAN" << endl;
    }
}

int main()
{
    // Menampilkan output
    cout << "BINARY SEARCH" <<endl;
    cout << "\nData : " <<endl;

    // Perulangan untuk enampilkan data
    for(int x = 0; x < 7; x++ ){
        cout << setw(3) << dataArray[x] ;
    }

    cout << endl;

    // Untuk input data yang akan dicari
    cout << "Masukkan data yang ingin dicari : " ;
    cin >> cari;

    // Untuk mengurutkan data
    cout << "\nData diurutkan : " ;
    selection_sort();

    // Perulangan untuk menampilkan data setelah diurutkan
    for (int x = 0; x < 7; x++){
        cout << setw(3) << dataArray[x];
    }
    cout <<endl;

    // Untuk mencari data
    binarySearch();
    _getche();
    return 0;
}