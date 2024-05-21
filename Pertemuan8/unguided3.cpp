#include <iostream>
using namespace std;

int main()
{
    // variable untuk data, cari, ketemu dan jumlah untuk menampung sebuah data
    int n = 10;
    int data_128[n] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int jumlah_128 = 0;
    int cari_128;
    bool ketemu_128 = false;

    // proses pencarian
    cout << "=============================================\n";
    cout << "Program Sequential Search" << endl;
    cout << "Data: {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}" << endl;
    cout << "=============================================\n";
    // input angka yang akan dicari
    cout << "Masukkan angka yang ingin dicari : ";
    cin >> cari_128;
    // perulangan untuk mencari nilai pada data dengan cara mencocokan data dengan angka yang dicari
    for (int i = 0; i < n; i++)
    {
        if (data_128[i] == cari_128)
        {
            ketemu_128 = true;
            jumlah_128++;
        }
    }
    // percabangan ketika nilai cari di temukan pada data
    if (ketemu_128)
    {
        cout << "=============================================\n";
        cout << "Angka '" << cari_128 << "' ditemukan sebanyak " << jumlah_128 << " pada data" << endl;
    }
    else
    {
        cout << cari_128 << " tidak ditemukan pada data tersebut." << endl;
    }
    cout << "=============================================\n";
    return 0;
}