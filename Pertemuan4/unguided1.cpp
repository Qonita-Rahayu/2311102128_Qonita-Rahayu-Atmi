#include <iostream>
#include <iomanip>
using namespace std;
// Mendeklarasikan struct
struct Node
{
    string nama_128;
    string NIM_128;
    string namaLama_128;
    string namaBaru_128;
    Node *next;
    Node *prev;
};
Node *head;
Node *tail;
// Menginisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}
// Pengecekan NULL untuk data kosong atau tidak
bool isEmpty()
{
    if (head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// Prosedur tambah data
// Prosedur untuk tambah data depan
void insertDepan(string nama_128, string NIM_128)
{
    Node *baru = new Node;
    baru->nama_128 = nama_128;
    baru->NIM_128 = NIM_128;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}
// Prosedur untuk tambah data belakang
void insertBelakang(string nama_128, string NIM_128)
{
    Node *baru = new Node;
    baru->nama_128 = nama_128;
    baru->NIM_128 = NIM_128;
    baru->next = NULL;
    if (isEmpty())
    {
        head = tail = baru;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}

// Fungsi Hitung Jumlah
int hitung_jumlah()
{
    Node *hitung = head;
    int jumlah = 0;

    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }

    return jumlah;
}
// Prosedur untuh tambah data di tengah
void insertTengah(string nama_128, string NIM_128, int posisi)
{
    Node *baru = new Node;
    baru->nama_128 = nama_128;
    baru->NIM_128 = NIM_128;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
    }
    else
    {
        Node *bantu = head;
        int nomor = 1;
        while (nomor < posisi)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
// Prosedur ubah data
// Prosedur untuk ubah data depan
void ubahDepan(string nama_128,  string namaBaru_128 ,string NIM_128)
{
     if (!isEmpty())
    {
        if (head->nama_128 == nama_128)
        {
            head->nama_128 = namaBaru_128;
            head->NIM_128 = NIM_128;
            cout << "Data (" << nama_128 << ") telah diganti dengan data (" << namaBaru_128 << ")" << endl;
        }
        else
        {
            cout << "Data dengan nama " << nama_128 << " tidak ditemukan!" << endl;
        }
    }
    else
    {
        cout << "List masih null!" << endl;
    }
}
// Prosedur untuk ubah data belakang
void ubahBelakang(string nama_128, string namaBaru_128,string NIM_128)
{
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->nama_128 == nama_128)
        {
            temp->nama_128 = namaBaru_128;
            temp->NIM_128 = NIM_128;
            cout << "Data (" << nama_128 << ") telah diganti dengan data (" << namaBaru_128 << ")" << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Data tidak ditemukan" << endl;
}
// Prosedur untuk ubah data di tengah
void ubahTengah(int posisi_128, string nama_128, string NIM_128, string namaBaru_128)
{
    if (!isEmpty())
    {
        if (posisi_128 < 1 || posisi_128 > hitung_jumlah())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else
        {
            Node *bantu = head;
            Node *sebelum = NULL; 

            int nomor = 1;

            // Iterasi hingga mencapai posisi yang diinginkan
            while (nomor < posisi_128 && bantu != NULL)
            {
                sebelum = bantu;
                bantu = bantu->next;
                nomor++;
            }

            // Cek apakah posisi yang diinginkan ditemukan
            if (bantu != NULL)
            {
                // Ubah data pada node yang ditemukan
                if (bantu->nama_128 == nama_128)
                {
                    bantu->nama_128 = namaBaru_128;
                    bantu->NIM_128 = NIM_128;
                    cout << "Data (" << nama_128 << ") telah diganti dengan data (" << namaBaru_128 << ")" << endl;

                    // Hubungkan node sebelumnya dengan node yang baru
                    if (sebelum != NULL)
                    {
                        Node *baru = new Node;
                        baru->nama_128 = namaBaru_128;
                        baru->NIM_128 = NIM_128;
                        baru->next = bantu->next;
                        sebelum->next = baru;
                    }
                }
                else
                {
                    cout << "Data dengan nama " << nama_128 << " tidak ditemukan pada posisi yang dimaksud!" << endl;
                }
            }
            else
            {
                cout << "Posisi di luar jangkauan" << endl;
            }
        }
    }
    else
    {
        cout << "List masih null!" << endl;
    }
}

// Fungsi hapus data
// Fungsi untuk hapus data di depan dan mengembalikan nama yang akan dihapus
string deleteDepan()
{
    // Menyimpan nama yang dihapus
    string nama_hapus = "";

    if (!isEmpty())
    {
        Node *hapus = head;

        if (head->next != NULL)
        {
            head = head->next;
            nama_hapus = hapus->nama_128;
            delete hapus;
        }
        else
        {
            nama_hapus = head->nama_128;
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List null!" << endl;
    }
    return nama_hapus; 
}
// Fungsi untuk hapus data di belakang dan mengembalikan nama yang akan dihapus
string deleteBelakang()
{
    // Menyimpan nama yang dihapus
    string namaHapus = ""; 

    if (!isEmpty())
    {
        Node *hapus = tail;
        Node *bantu = head;

        if (head != tail)
        {
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }

            tail = bantu;
            tail->next = NULL;
            namaHapus = hapus->nama_128; 
            delete hapus;
        }
        else
        {
            namaHapus = head->nama_128; 
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List null!" << endl;
    }

    return namaHapus;
}
// Fungsi untuk hapus data di tengah dan untuk mengembalikan nama yang akan dihapus
string deleteTengah(int posisi_128)
{
    // Menyimpan nama yang dihapus
    string namaHapus = ""; 

    if (posisi_128 < 1 || posisi_128 > hitung_jumlah())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi_128 == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *hapus;
        Node *bantu;
        Node *bantuan;
        int nomor = 1;
        bantu = head;

        while (nomor <= posisi_128)
        {
            if (nomor == posisi_128 - 1)
            {
                bantuan = bantu;
            }

            if (nomor == posisi_128)
            {
                hapus = bantu;
                namaHapus = hapus->nama_128; 
            }

            bantu = bantu->next;
            nomor++;
        }

        bantuan->next = bantu;
        delete hapus;
    }
    // Kembalikan nama yang dihapus
    return namaHapus; 
}
// Prosedur untuk menghapus semua data
void hapusSemua()
{
    Node *bantu = head;
    Node *hapus;

    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }

    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
// Prosedur untuk tampilkan semua data
void tampil()
{
    Node *bantu = head;
    if (!isEmpty()) 
    {
        cout << "|------------------------------|" << endl;
        cout << "|        DATA MAHASISWA        |" << endl;
        cout << "|------------------------------|" << endl;
        cout << "|       Nama      |    NIM     |" << endl;
        cout << "|------------------------------|" << endl;
        while (bantu != NULL)
        {
            cout << "| " << setw(15) << left << bantu->nama_128 << " | " << setw(10) << left << bantu->NIM_128 << " |" << endl;
            bantu = bantu->next;
        }
        cout << "|------------------------------|" << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Prosedur untuk menghapus nama
void hapusData(string nama_128)
{
    if (isEmpty())
    {
        cout << "List masih kosong!" << endl;
        return;
    }
    Node *bantu = head;
    Node *sebelum = NULL;

    while (bantu != NULL && bantu->nama_128 != nama_128)
    {
        sebelum = bantu;
        bantu = bantu->next;
    }

    if (bantu == NULL)
    {
        cout << "Data tidak ditemukan!" << endl;
        return;
    }

    if (sebelum == NULL)
    {
        deleteDepan();
    }
    else
    {
        sebelum->next = bantu->next;
        delete bantu;
        cout << "Data dengan nama " << nama_128 << " berhasil dihapus!" << endl;
    }
}
int main()
{
    string nama_128, NIM_128, namaBaru_128;
    int pilihan_128, posisi_128;

    do
    {
        // Menampilkan pilihan menu
        cout << "|=========================================|" << endl;
        cout << "| PROGRAM SINGLE LINKED LIST NON-CIRCULAR |" << endl;
        cout << "|=========================================|" << endl;
        cout << "|1. Tambah Depan                          |" << endl;
        cout << "|2. Tambah Belakang                       |" << endl;
        cout << "|3. Tambah Tengah                         |" << endl;
        cout << "|4. Ubah Depan                            |" << endl;
        cout << "|5. Ubah Belakang                         |" << endl;
        cout << "|6. Ubah Tengah                           |" << endl;
        cout << "|7. Hapus Depan                           |" << endl;
        cout << "|8. Hapus Belakang                        |" << endl;
        cout << "|9. Hapus Tengah                          |" << endl;
        cout << "|10. Hapus List                           |" << endl;
        cout << "|11. Tampilkan                            |" << endl;
        cout << "|0. Keluar                                |" << endl;
        cout << "|=========================================|" << endl;
        cout << "Pilihan Operasi: ";
        cin >> pilihan_128;

        switch (pilihan_128)
        {
        case 0:
            break;
        // Untuk menambah data depan
        case 1:
            cout << "-Tambah Depan-" << endl;
            cout << "Masukkan Nama : ";
            cin >> nama_128;
            cout << "Masukkan NIM : ";
            cin >> NIM_128;
            insertDepan(nama_128, NIM_128);
            cout << "Data telah ditambahkan" << endl;
            break;
        // Untuk menambah data belakang    
        case 2:
            cout << "-Tambah Belakang-" << endl;
            cout << "Masukkan Nama : ";
            cin >> nama_128;
            cout << "Masukkan NIM : ";
            cin >> NIM_128;
            insertBelakang(nama_128, NIM_128);
            cout << "Data telah ditambahkan" << endl;
            break;
        // Untuk menambah data tengah    
        case 3:
            cout << "-Tambah Tengah-" << endl;
            cout << "Masukkan Nama : ";
            cin >> nama_128;
            cout << "Masukkan NIM : ";
            cin >> NIM_128;
            cout << "Masukkan Posisi : ";
            cin >> posisi_128;
            insertTengah(nama_128, NIM_128, posisi_128);
            cout << "Data telah ditambahkan" << endl;
            break;
        // Untuk mengubah data depan    
        case 4:
            cout << "-Ubah Depan-" << endl;
            cout << "Masukkan Nama yang diubah : ";
            cin >> nama_128;
            cout << "Masukkan Nama Baru : ";
            cin >> namaBaru_128;
            cout << "Masukkan NIM Baru : ";
            cin >> NIM_128;
            ubahDepan(nama_128, namaBaru_128, NIM_128);
            cout << "Data dengan nama " << nama_128 << " telah diubah menjadi " << namaBaru_128 << endl;
            break;
        // Untuk mengubah data belakang    
        case 5:
            cout << "-Ubah Belakang-" << endl;
            cout << "Masukkan nama yang diubah : ";
            cin >> nama_128;
            cout << "Masukkan Nama Baru : ";
            cin >> namaBaru_128;
            cout << "Masukkan NIM Baru : ";
            cin >> NIM_128;
            ubahBelakang(nama_128, namaBaru_128, NIM_128);
            cout << "Data dengan nama " << nama_128 << " telah diubah menjadi " << namaBaru_128 << endl;
            break;
        // Untuk mengubah data tengah
        case 6: 
            cout << "-Ubah Tengah-" << endl;
            cout << "Masukkan nama yang diubah : ";
            cin >> nama_128;
            cout << "Masukkan Nama Baru : ";
            cin >> namaBaru_128;
            cout << "Masukkan NIM Baru : ";
            cin >> NIM_128;
            cout << "Masukkan Posisi : ";
            cin >> posisi_128;
            ubahTengah(posisi_128, nama_128, NIM_128, namaBaru_128);
            cout << "Data dengan nama " << nama_128 << " telah diubah menjadi " << namaBaru_128 << endl;
            break;
        // Untuk menghapus data depan
        case 7:
            cout << "-Hapus Depan-" << endl;  
            cout << "Data dengan nama " << deleteDepan() << " berhasil dihapus" << endl;
            break;
        // Untuk menghapus data belakang
        case 8:
            cout << "-Hapus Belakang-" << endl;
            cout << "Data dengan nama " << deleteBelakang() << " berhasil dihapus" << endl;
            break;
        // Untuk menghapus data tengah
        case 9:
            cout << "-Hapus Tengah-" << endl;
            cout << "Masukkan Posisi : ";
            cin >> posisi_128;
            cout << "Data dengan nama " << deleteTengah(posisi_128) << " berhasil dihapus" << endl;
            break;
        // Untuk menghapus semua data
        case 10:
            cout << "-Hapus List-" << endl;
            hapusSemua();
            cout << "Data berhasil dihapus" << endl;
            break;
        // Untuk menampilkan ke menu utama
        case 11:
            tampil();
            break;
        default:
            cout << "Program Selesai" << endl;
            break;
        }

    } while (pilihan_128 != 0);

    return 0;
}