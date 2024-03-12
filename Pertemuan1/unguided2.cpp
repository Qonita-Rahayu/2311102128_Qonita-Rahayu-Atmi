#include <iostream>
using namespace std;

// Class untuk menampung data
class karyawan
{
public:
    string nama_128;
    int umur_128;
    string alamat_128;
};
struct siswa
{
    string nama_128;
    int umur_128;
    string alamat_128;
};
int main()
{
    // Menambahkan data class karyawan
    cout <<endl;
    cout << "Menampilkan Class karyawan"<< endl;
    karyawan Karyawan_128;
    Karyawan_128.nama_128 = "Budi";
    Karyawan_128.umur_128 = 27;
    Karyawan_128.alamat_128 = "Sokawera";

    // Menampilkan class karyawan
    cout << "Nama: " << Karyawan_128.nama_128 << endl;
    cout << "Umur: " << Karyawan_128.umur_128 << endl;
    cout << "Alamat: " << Karyawan_128.alamat_128 << endl;

    // Menambahkan data struct siswa
    cout <<endl;
    cout << "Menampilkan Struct mykaryawan"<< endl;
    siswa Siswa_128;
    Siswa_128.nama_128 = "Joko";
    Siswa_128.umur_128 = 20;
    Siswa_128.alamat_128 = "Banyummas";

    // Menampilkan struct siswa
    cout << "Nama: " << Siswa_128.nama_128 << endl;
    cout << "Umur: " << Siswa_128.umur_128 << endl;
    cout << "Alamat: " << Siswa_128.alamat_128 << endl;
    return 0;
}