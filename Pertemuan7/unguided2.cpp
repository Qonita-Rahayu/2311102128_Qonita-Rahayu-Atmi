#include <iostream>
using namespace std;

// Nilai maksimal data antrian mahasiswa
const int Maks_128= 5;

// Untuk membuat struct node class Queue
struct Node
{
    string nama_128;
    string NIM_128;
    Node *next;
};

// Untuk membuat class Queue
class Queue_128
{
private:
    Node *front;
    Node *rear;
    int size;

    // Insialisasi Queue
public:
    Queue_128()
    {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    // Untuk mengecek apakah antrian penuh atau tidak pada queue data mahasiswa
    bool isFull()
    {
        return size == Maks_128;
    }

    // Untuk mengecek apakah antrian kosong atau tidak pada queue data mahasiswa
    bool isEmpty()
    {
        return size == 0;
    }

    // Untuk menambahkan data mahasiswa pada antrian
    void enQueue(string nama_128, string NIM_128)
    {
        // Jika antrian penuh maka akan mengeluarkan pesan
        if (isFull())
        {
            cout << "Antrian penuh" << endl;
            return;
        }
        Node *newNode = new Node;
        newNode->nama_128 = nama_128;
        newNode->NIM_128 = NIM_128;
        newNode->next = nullptr;
        // Jika antrian masih kosong maka data baru ditambahkan
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    // Untuk mengeluarkan data mahasiswa dari antrian
    void deQueue()
    {
        if (isEmpty())
        {
            cout << "Antrian kosong" << endl;
            return;
        }
        Node *temp = front;
        front = front->next;
        delete temp;
        size--;
    }

    // Untuk menampilkan semua data mahasiswa pada antrian
    void viewQueue()
    {
        cout << "Data antrian mahasiswa:" << endl;
        if (isEmpty())
        {
            for (int i = 0; i < Maks_128; i++)
            {
                cout << i + 1 << ". (kosong)" << endl;
            }
        }
        else
        {
            Node *current = front;
            int pos = 1;
            while (current != nullptr)
            {
                cout << pos++ << ". Nama: " << current->nama_128 << ", NIM: " << current->NIM_128 << endl;
                current = current->next;
            }
            // Jika masih tersisa ruang di antrian, tampilkan sebagai (kosong)
            for (int i = size; i < Maks_128; i++)
            {
                cout << i + 1 << ". (kosong)" << endl;
            }
        }
    }

    // Untuk menghitung jumlah data mahasiswa dalam antrian
    int countQueue()
    {
        return size;
    }

    // Untuk mengosongkan semua data mahasiswa dalam antrian
    void clearQueue()
    {
        while (!isEmpty())
        {
            deQueue();
        }
    }
};

int main()
{
    // Untuk menambahkan data mahasiswa pada antrian
    Queue_128 mahasiswaQueue_128;
    mahasiswaQueue_128.enQueue("Rahayu Atmi", "231110212");
    mahasiswaQueue_128.enQueue("Qonita Rahayu Atmi", "2311102128");
    // Untuk melihat semua data mahasiswa pada antrian
    mahasiswaQueue_128.viewQueue();
    // Untuk menghitung data mahasiswa dari antrian
    cout << "Jumlah antrian = " << mahasiswaQueue_128.countQueue() << endl;
    // Untuk mengeluarkan data mahasiswa dari antrian
    mahasiswaQueue_128.deQueue();
    // Untuk melihat semua data mahasiswa pada antrian
    mahasiswaQueue_128.viewQueue();
    // Untuk menghitung data mahasiswa dari antrian
    cout << "Jumlah antrian = " << mahasiswaQueue_128.countQueue() << endl;
    // Untuk menghapus semua data mahasiswa pada antrian
    mahasiswaQueue_128.clearQueue();
    // Untuk melihat semua data mahasiswa pada antrian
    mahasiswaQueue_128.viewQueue();
    // Untuk menghitung data mahasiswa dari antrian
    cout << "Jumlah antrian = " << mahasiswaQueue_128.countQueue() << endl;
    return 0;
}