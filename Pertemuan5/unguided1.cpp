#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Untuk mendeklarasi konstanta TABLE_SIZE
const int TABLE_SIZE = 10;

// Untuk mendeklarasi struct hash_node
struct hash_node
{
    string NIM_128;
    string nama_128;
    int nilai_128;
};

// Untuk mendeklarasi array tabel hash
hash_node *table[TABLE_SIZE];

// Fungsi hash untuk menghasilkan indeks dari NIM
int hashfunc(string key)
{
    int index = 0;
    for (char i : key)
    {
        index += i;
    }
    return index % TABLE_SIZE;
}

// Fungsi untuk menambahkan data mahasiswa ke dalam tabel hash
void insert_128(string NIM_128, string nama_128, int nilai_128)
{
    int index = hashfunc(NIM_128);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[index] == nullptr)
        {
            table[index] = new hash_node{NIM_128, nama_128, nilai_128};
            cout << "Data mahasiswa berhasil ditambahkan." << endl;
            return;
        }
        index = (index + 1) % TABLE_SIZE;
    }
    cout << "Tabel hash penuh. Data mahasiswa tidak dapat ditambahkan." << endl;
}

// Fungsi untuk menghapus data mahasiswa dari tabel hash berdasarkan NIM
void delete_128(string NIM_128)
{
    int index = hashfunc(NIM_128);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[index] != nullptr && table[index]->NIM_128 == NIM_128)
        {
            delete table[index];
            table[index] = nullptr;
            cout << "Data mahasiswa dengan NIM " << NIM_128 << " berhasil dihapus." << endl;
            return;
        }
        index = (index + 1) % TABLE_SIZE;
    }
    cout << "Data mahasiswa dengan NIM " << NIM_128 << " tidak ditemukan." << endl;
}

// Fungsi untuk mencari data mahasiswa berdasarkan NIM
hash_node *search_128(string NIM_128)
{
    int index = hashfunc(NIM_128);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[index] != nullptr && table[index]->NIM_128 == NIM_128)
        {
            return table[index];
        }
        index = (index + 1) % TABLE_SIZE;
    }
    return nullptr;
}

// Fungsi untuk mencari data mahasiswa berdasarkan rentang nilai
vector<hash_node *> search_nilai_128(int minScore, int maxScore)
{
    vector<hash_node *> result;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[i] != nullptr && table[i]->nilai_128 >= minScore && table[i]->nilai_128 <= maxScore)
        {
            result.push_back(table[i]);
        }
    }
    return result;
}

// Fungsi untuk mencetak data mahasiswa dalam bentuk tabel
void print_128()
{
    cout << "|---------------------------------------------|" << endl;
    cout << "| No.  | NIM       | Nama          | Nilai    |" << endl;
    cout << "|---------------------------------------------|" << endl;
    int no = 1;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[i] != nullptr)
        {
      cout << "| " << setw(4) << no++ << " | " << setw(10) << table[i]->NIM_128 << " | " << setw(14) << table[i]->nama_128 << " | " << setw(7) << table[i]->nilai_128 << " |" << endl;
        }
    }
    cout << "-----------------------------------------------" << endl;
}

// Fungsi utama
int main()
{
    // Mendeklarasikan variabel
    int pilihan_128;
    string NIM_128;
    string nama_128;
    int nilai_128;

    do
    {
        // Untuk menampilkan menu pilihan
        cout << "Menu:" << endl;
        cout << "1. Tambah data mahasiswa" << endl;
        cout << "2. Hapus data mahasiswa" << endl;
        cout << "3. Cari data mahasiswa berdasarkan NIM" << endl;
        cout << "4. Cari data mahasiswa berdasarkan rentang nilai (80-90)" << endl;
        cout << "5. Tampilkan data mahasiswa" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilihan_128;

        switch (pilihan_128)
        {
        // Untuk menambah data mahasiswa
        case 1:
            cout << "Masukkan nama mahasiswa : ";
            cin.ignore();
            getline(cin, nama_128);
            cout << "Masukkan NIM mahasiswa : ";
            cin >> NIM_128;
            cout << "Masukkan nilai mahasiswa : ";
            cin >> nilai_128;
            insert_128(NIM_128, nama_128, nilai_128);
            break;
        // Untuk menghapus data mahasiswa
        case 2:
            cout << "Masukkan NIM mahasiswa yang ingin dihapus : ";
            cin >> NIM_128;
            delete_128(NIM_128);
            break;
        // Untuk mencari data mahasiswa berdasarkan NIM
        case 3:
            cout << "Masukkan NIM mahasiswa yang ingin dicari: ";
            cin >> NIM_128;
            {
                hash_node *mahasiswa = search_128(NIM_128);
                if (mahasiswa != nullptr)
                {
                    cout << "Nama mahasiswa dengan NIM : " << NIM_128 << ", Nama : " << mahasiswa->nama_128 << ", Nilai: " << mahasiswa->nilai_128 << endl;
                }
                else
                {
                    cout << "Mahasiswa dengan NIM : " << NIM_128 << " tidak ditemukan" << endl;
                }
            }
            break;
        // Untuk mencari data mahasiswa berdasarkan rentang nilai 80-90
        case 4:
            cout << "Mahasiswa dengan nilai antara 80 dan 90:" << endl;
            {
                vector<hash_node *> mahasiswaInRange = search_nilai_128(80, 90);
                if (mahasiswaInRange.empty())
                {
                    cout << "Tidak ada mahasiswa dalam rentang nilai tersebut" << endl;
                }
                else
                {
                    for (auto mahasiswa : mahasiswaInRange)
                    {
                        cout << "NIM: " << mahasiswa->NIM_128 << ", Nama: " << mahasiswa->nama_128 << ", Nilai: " << mahasiswa->nilai_128 << endl;
                    }
                }
            }
            break;
        // Untuk mampilkan data mahasiswa
        case 5:
            cout << "Data mahasiswa:" << endl;
            print_128();
            break;
        case 6:
            cout << "Keluar." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan_128 != 6);

    return 0;
}