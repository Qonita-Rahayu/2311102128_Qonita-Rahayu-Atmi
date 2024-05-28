#include <iostream>
#include <iomanip>

// Program Graph
using namespace std;
// Mendeklarasikan variabel simpul yang berisi nama-nama kota
string simpul[7] = {
    "Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"
};
// Fungsi untuk array 2 dimensi yang dibuat 7 baris dan 7 kolom
int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0}
};

// Prosedur untu menampilkan graph
void tampilGraph()
{
    // Perulangan untuk menampilkan baris
    for (int baris = 0; baris < 7; baris++)
    {
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << " : ";
        // Perulangan untuk menampilkan kolom
        for (int kolom = 0; kolom < 7; kolom++)
        {
            if (busur[baris][kolom] != 0)
            {
                cout << " " << simpul[kolom] << " ( " << busur [baris][kolom] << " ) ";
            }
        }cout << endl;
    }
}
int main()
{
    // Untuk menampilkan graph
    tampilGraph();
    return 0;
}