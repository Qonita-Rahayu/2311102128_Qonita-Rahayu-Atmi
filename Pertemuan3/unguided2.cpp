#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;
// Mendeklarasikan class
struct Node{
    string nama_produk_128;
    int harga_128;
    Node *next;
    Node *prev;
};
Node *head, *tail;
// Prosedure untuk menginisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}

// Untuk pengecekan NULL
bool isEmpty(){
    if (head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// untuk menambah data
// Prosedure untuk menambahkan data insert depan
void insertDepan(string nama_produk_128, int harga_128)
{
    Node *baru = new Node;
    baru->nama_produk_128 = nama_produk_128;
    baru->harga_128 = harga_128;
    baru->prev = NULL;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
    }
    else
    {
        baru->next = head;
        head->prev = baru;
        head = baru;
    }
}
// Prosedure untuk menambah data insert belakang
void insertBelakang(string nama_produk_128, int harga_128)
{
    Node *baru = new Node;
    baru->nama_produk_128 = nama_produk_128;
    baru->harga_128 = harga_128;
    baru->prev = NULL;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
    }
    else
    {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
}
// Prosedure untuk menambah data insert tengah
void insertTengah(string nama_produk_128, int harga_128, int posisi_128)
{
    Node *baru = new Node;
    baru->nama_produk_128 = nama_produk_128;
    baru->harga_128 = harga_128;
    baru->prev = NULL;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
    }
    else
    {
        Node *bantu = head;
        int nomor = 1;
        while (nomor < posisi_128 - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next->prev = baru;
        bantu->next = baru;
        baru->prev = bantu;
    }
}
// untuk menghapus data
// Prosedure untuk menghapus data insert depan
void hapusDepan()
{
    if (isEmpty() == false)
    {
        if (head->next != NULL)
        {
            Node *hapus = head;
            head = head->next;
            head->prev = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Prosedure untuk menghapus data insert belakang
void hapusBelakang()
{
    if (isEmpty() == false)
    {
        if (head->next != NULL)
        {
            Node *hapus = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
};
// Prosedure untuk menghapus data insert tengah
int hitung_jumlah();
void hapusTengah(int posisi_128)

{
    if (posisi_128 < 1 || posisi_128 > hitung_jumlah())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi_128 == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *hapus = head;
        Node *bantu = head;
        int nomor = 1;

        while (nomor < posisi_128 - 1)
        {
            bantu = bantu->next;
            nomor++;
        }

        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    } 
}
// Fungsi untuk menghitung jumlah
int hitung_jumlah()
{
    Node *hitung = head;
    int jumlah = 0;

    while (hitung != NULL)
    {
        hitung = hitung->next;
        jumlah++;
    }
    return jumlah;

}
// Prosedure untuk meperbarui data
void update(int posisi_128, string nama_produk_128, int harga_128)
{
    if (posisi_128 < 1 || posisi_128 > hitung_jumlah())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi_128 == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *bantu = head;
        int nomor = 1;
        while (nomor < posisi_128)
        {
            bantu = bantu->next;
            nomor++;
        }
        bantu->nama_produk_128 = nama_produk_128;
        bantu->harga_128 = harga_128;
    }
}
// Prosedure untuk menghapus semua data
void hapusSemua()
{
    if (isEmpty() == false)
    {
        Node *bantu = head;
        while (bantu != NULL)
        {
            Node *hapus = bantu;
            bantu = bantu->next;
            delete hapus;
        }
        head = tail = NULL;
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Prosedure untuk menampilkan data
void display()
{
    Node *bantu = head;

    if (!isEmpty())
    {
        cout << "|-------------------------|" << endl;
        cout << "|    Produk  |   Harga    |" << endl;
        cout << "|-------------------------|" << endl;
        while (bantu != NULL)
        {
            cout << "| " << setw(10) << left << bantu->nama_produk_128<< " | " << setw(10) << left << bantu->harga_128 << " |" << endl;
            bantu = bantu->next;
        }
        cout << "|-------------------------|" << endl;
    }
    else
    {
        cout << "List masih null!" << endl;
    }
}
int main()
{
    //Inisialisasi
    init();
    //Untuk menambahkan data
    insertDepan   ("Originote", 60000);
    insertBelakang("Somethinc", 150000);
    insertBelakang("Skintific", 100000);
    insertBelakang("Wardah"   , 50000);
    insertBelakang("Hanasui"  , 30000);

    //Untuk menampilkan display
    display();

    //Untuk menambahkan menu
    int pilihan_128;
    string nama_produk_128;
    int harga_128;
    int posisi_128;
    do
    {
        cout << "Toko Skincare Purwokerto: " << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan_128;

        switch (pilihan_128)
        {
        case 1:
            // Untuk menambahkan data
            cout << "Masukkan nama produk: ";
            cin >> nama_produk_128;
            cout << "Masukkan harga : ";
            cin >> harga_128;
            insertDepan(nama_produk_128, harga_128);
            break;
        case 2:
            // Untuk menghapus data
            cout << "Masukkan nama produk yang ingin dihapus: ";
            cin >> nama_produk_128;
            cout << "Masukkan posisi data yang ingin dihapus: ";
            cin >> posisi_128;
            hapusDepan();
            break;
        case 3:
            // Untuk mengupdate data
            cout << "Masukkan nama produk yang ingin diupdate: ";
            cin >> nama_produk_128 ;
            cout << "Masukkan harga produk yang ingin diupdate: ";
            cin >> harga_128;
            cout << "Masukkan posisi data yang ingin diupdate: ";
            cin >> posisi_128;
            update(posisi_128, nama_produk_128, harga_128);
            break;
        case 4:
            // Untuk menambahkan data urutan tertentu
            cout << "Masukkan posisi data yang ingin ditambahkan: ";
            cin >> posisi_128;
            cout << "Masukkan nama produk baru: ";
            cin >> nama_produk_128 ;
            cout << "Masukkan harga produk baru: ";
            cin >> harga_128;
            insertTengah(nama_produk_128, harga_128, posisi_128);
            break;
        case 5:
            // Untuk menghapus data urutan tertentu
            cout << "Masukkan posisi data yang ingin dihapus: ";
            cin >> posisi_128;
            hapusTengah(posisi_128);
            break;
        case 6:
            // Untuk menghapus semua data
            hapusSemua();
            break;
        case 7:
            // Untuk menampilkan data
            cout << "Daftar produk Toko Skincare: " << endl;
            display();
            break;
        case 8:
            // Untuk keluar dari program
            cout << "Terima kasih telah belanja di Toko Skincare Purwokerto" << endl;
            break;
        default:
            cout << "Pilihan tidak valid" << endl;
            break;
        }
    } while (pilihan_128 != 8);

    

return 0;
}