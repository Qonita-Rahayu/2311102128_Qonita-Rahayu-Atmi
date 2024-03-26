#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

//Mendeklarasikan struct
struct Node {
    string nama_128;
    int umur_128;
    Node *next;
};
Node *head;
Node *tail;
// Menginisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}
// Pengecekan NULL
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
// Prosedure untuk memasukkan data 
// Prosedure untuk memasukkan data insert depan
void insertDepan(string nama_128, int umur_128)
{
    Node *baru = new Node;
    baru->nama_128 = nama_128;
    baru->umur_128 = umur_128;
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
// Prosedure untuk insert belakang
void insertBelakang(string nama_128, int umur_128)
{
    Node *baru = new Node;
    baru->nama_128 = nama_128;
    baru->umur_128 = umur_128;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}
// Prosedure untuk insert tengah
void insertTengah(string nama_128, int umur_128, int posisi_128)
{
    Node *baru = new Node;
    baru->nama_128 = nama_128;
    baru->umur_128 = umur_128;
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
        bantu->next = baru;
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
// Untuk menghapus data
// Prosedure untuk hapus depan
void hapusDepan()
{
    if (isEmpty() == false)
    {
        if (head->next != NULL)
        {
            Node *hapus = head;
            head = head->next;
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
// Prosedure untuk hapus belakang
void hapusBelakang()
{
    if (isEmpty() == false)
    {
        if (head->next != NULL)
        {
            Node *hapus = tail;
            Node *bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            tail = bantu;
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
}
// Prosedure untuk hapus tengah
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
// Untuk ubah data
// Prosedure untuk mengubah depan
void ubahDepan(string nama_128, int umur_128)
{
    if (isEmpty() == false)
    {
        head->nama_128 = nama_128;
        head->umur_128 = umur_128;
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Prosedure untuk mengubah belakang
void ubahBelakang(string nama_128, int umur_128)
{
    if (isEmpty() == false)
    {
        tail->nama_128 = nama_128;
        tail->umur_128 = umur_128;
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Prosedure untuk mengubah tengah
void ubahTengah(string nama_128, int umur_128, int posisi_128)
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

        bantu->nama_128 = nama_128;
        bantu->umur_128 = umur_128;
        
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
// Prosedure untuk menampilkan display
void display(){
    Node *bantu = head;

    if (!isEmpty())
    {
        cout << "|-------------------------|" << endl;
        cout << "|    Nama    |    Umur    |" << endl;
        cout << "|-------------------------|" << endl;
        while (bantu != NULL)
        {
            cout << "| " << setw(10) << left << bantu->nama_128<< " | " << setw(10) << left << bantu->umur_128 << " |" << endl;
            bantu = bantu->next;
        }
        cout << "|-------------------------|" << endl;
    }
    else
    {
        cout << "List masih null!" << endl;
    }
}
int main(){
    
    //Untuk inisialisasi
    init();
    //Untuk menambahkan data diawali
    insertDepan("Karin", 18);
    insertDepan("Hoshino", 18);
    insertDepan("Akechi", 20);
    insertDepan("Yusuke", 19);
    insertDepan("Michael", 18);
    insertDepan("Jane", 20);
    insertDepan("John", 19);

    //Untuk menampilkan data diawali
    cout << "Data Mahasiswa : " << endl;
    display();
    cout << endl;

    //Pilihan Menu
    int pilihan_128;
    string nama_128;
    int umur_128;
    int posisi_128;

    do{

        cout << "Data Mahasiswa :" << endl;
        cout << "1. Tambahkan Data Mahasiswa" << endl;
        cout << "2. Hapus Data Mahasiswa" << endl;
        cout << "3. Update Data Mahasiswa" << endl;
        cout << "4. Tambahkan Data Mahasiswa Urutan Tertentu" << endl;
        cout << "5. Hapus Data Mahasiswa Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data Mahasiswa" << endl;
        cout << "7. Tampilkan Data Mahasiswa" << endl;
        cout << "8. Exit" << endl;
        cout << "Pilihan: ";
        cin >> pilihan_128;

        switch(pilihan_128){
            //Menambahkan data
            case 1:
                cout << "Masukkan Nama: ";
                cin >> nama_128;
                cout << "Masukkan Umur: ";
                cin >> umur_128;
                insertDepan(nama_128, umur_128);
                break;
            //Menghapus data    
            case 2:
                hapusDepan();
                break;
            //Mengubah data    
            case 3:
                cout << "Masukkan Nama: ";
                cin >> nama_128;
                cout << "Masukkan Umur: ";
                cin >> umur_128;
                cout << "Masukkan Posisi: ";
                cin >> posisi_128;
                ubahTengah(nama_128, umur_128, posisi_128);
                break;
            //Menambahkan data di posisi antara   
            case 4:
                cout << "Masukkan Nama: ";
                cin >> nama_128;
                cout << "Masukkan Umur: ";
                cin >> umur_128;
                cout << "Masukkan Posisi: ";
                cin >> posisi_128;
                insertTengah(nama_128, umur_128, posisi_128);
                break;
            //Menghapus data di posisi antara    
            case 5:
                cout << "Masukkan Posisi: ";
                cin >> posisi_128;
                cout << "Masukkan Nama Mahasiswa yang akan dihapus: ";
                cin >> nama_128;
                cout << "Masukkan Umur Mahsiswa yang akan dihapus: ";
                cin >> umur_128;
                hapusTengah(posisi_128);
                break;
            //Menghapus semua data    
            case 6:
                hapusSemua();
                break;
            //Menampilkan semua data    
            case 7:
                cout << "Data Mahasiswa" << endl;
                display();
                break;
            //Program selesai    
            case 8:
                cout << "Program Selesai" << endl;
                break;
            default:
                cout << "Pilihan Tidak Tersedia" << endl;
                break;
        }
    }

    while(pilihan_128 != 8);

    return 0;   
}