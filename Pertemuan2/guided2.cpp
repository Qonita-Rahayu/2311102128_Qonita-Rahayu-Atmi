#include <iostream>
using namespace std;
int main()
{
    // variable untuk mencari nilai maksimum
    int maks, a, i = 1, lokasi;
    // input panjang array
    cout << "Masukkan panjang array: ";
    cin >> a;
    // input angka
    int array[a];
    cout << "Masukkan " << a << " angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "Array ke-" << (i) << ": ";
        cin >> array[i];
    }
    // mencari nilai maksimum pada data array yang di inputkan
    maks = array[0];
    for (i = 0; i < a; i++)
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi = i;
        }
    }
    // menampilkan nilai maksimum dan lokasi nilai maksimum pada indeks array
    cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi << endl;
}





