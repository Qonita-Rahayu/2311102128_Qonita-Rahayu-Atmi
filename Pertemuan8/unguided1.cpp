#include <iostream>
#include <string>

using namespace std;
// Fungsi untuk mengurutkan karakter atau huruf kedalam string menggunakan Bubble Sort
void bubbleSort(string & Kalimat_128)
{
    int n = Kalimat_128.size();
    // Perulangan untuk semua elemen dalam string
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (Kalimat_128[j] > Kalimat_128[j + 1])
            {r
                swap(Kalimat_128[j], Kalimat_128[j + 1]);
            }
        }
    }
}
// Fungsi untuk mencari karakter atau huruf dalam string yang sudah diurutkan menggunakan Binary Search
void binarySearch(const string & Kalimat_128, char cari_128)
{
    bool ditemukan = false;
    cout << "==================================================\n";
    cout << "Huruf '" << cari_128 << "' ditemukan pada indeks ke : ";
    // Perulangan untuk mencari huruf dalam string
    for (size_t i = 0; i < Kalimat_128.size(); ++i)
    {
        if (Kalimat_128[i] == cari_128)
        {
            ditemukan = true;
            cout << i << " ";
        }
    }
    cout << endl;
    // percabangan apabila huruf tidak ditemukan dalam kata atau huruf
    if (!ditemukan)
    {
        cout << "Huruf tersebut tidak ditemukan dalam kalimat." << endl;
    }
    cout << "==================================================\n";
}

int main()
{
    // variable kalimat dan cari
    string Kalimat_128;
    char cari_128;
    
    // input kalimat
    cout << "==================================================\n";
    cout << "Masukkan kalimat yang ingin Anda urutkan: ";
    getline(cin, Kalimat_128);
    cout << "==================================================\n";

    // Urutkan kalimat menggunakan bubble sort
    bubbleSort(Kalimat_128);
    cout << "Kalimat setelah Anda urutkan : " << Kalimat_128 << endl;

    cout << "Masukkan huruf yang ingin Anda cari : ";
    cin >> cari_128;

    // Cari huruf dalam kalimat menggunakan binary search
    binarySearch(Kalimat_128, cari_128);

    return 0;
}