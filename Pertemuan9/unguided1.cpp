#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

// Fungsi untuk menampilkan graf dalam bentuk matriks bobot
void tampilGraph(vector<string>& simpul_2311102128, vector<vector<int>>& busur_2311102128, int n) 
{
    // Untuk cetak header kolom (nama-nama simpul)
    cout << setw(15) << " ";
    for (int i = 0; i < n; i++) 
    {
        cout << setw(15) << simpul_2311102128[i];
    }
    cout << endl;

    // Untuk cetak setiap baris dalam matriks
    for (int baris = 0; baris < n; baris++)
    {
        // Untuk cetak nama simpul untuk baris saat ini
        cout << setw(15) << simpul_2311102128[baris];
        for (int kolom = 0; kolom < n; kolom++) 
        {
            // Untuk cetak bobot dari simpul baris ke simpul kolom
            cout << setw(15) << busur_2311102128[baris][kolom];
        }
        cout << endl;
    }
}

int main() 
{
    // Variabel 
    int n_2311102128;
    
    // Untuk memasukkan jumlah simpul
    cout << "Silakan masukan jumlah simpul: ";
    cin >> n_2311102128;

    // Untuk menyimpan nama-nama simpul vektor
    vector<string> simpul_2311102128(n_2311102128);
    cout << "Silakan masukan nama simpul\n";
    for (int i = 0; i < n_2311102128; i++) 
    {
        // Untuk memasukkan nama untuk setiap simpul
        cout << "Simpul " << i + 1 <<  " : ";
        cin >> simpul_2311102128[i];
    }

    // Untuk menyimpan bobot antar simpul matriks
    vector<vector<int>> busur_2311102128(n_2311102128, vector<int>(n_2311102128, 0));
    cout << "Silakan masukkan bobot antar simpul\n";
    for (int i = 0; i < n_2311102128; i++) 
    {
        for (int j = 0; j < n_2311102128; j++) 
        {
            // Untuk memasukkan bobot untuk setiap pasangan simpul
            cout << simpul_2311102128[i] << "--> " << simpul_2311102128[j] << " = ";
            cin >> busur_2311102128[i][j];
        }
    }

    // Fungsi tampilGraph untuk menampilkan matriks bobot
    tampilGraph(simpul_2311102128, busur_2311102128, n_2311102128);
    return 0;
}