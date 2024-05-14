#include <iostream>
using namespace std;

// nilai maksimal data antrian
const int Maks_128 = 5; 

// Membuat struct Node class Queue
struct Node
{
    string data_128;
    Node *next;
};

// Membuat class Queue
class Queue
{
private:
    Node *front;
    Node *rear;
    int size;

public:
    // Iniisialisasi Queue
    Queue()
    {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    // Untuk mengecek apakah antrian penuh atau tidak pada queue teller
    bool isFull()
    {
        return size == Maks_128;
    }

    // Untuk mengecek apakah antrian kosong atau tidak pada queue teller
    bool isEmpty()
    {
        return size == 0;
    }

    // Untuk menambahkan data teller pada antrian teller
    void enqueue(string data_128)
    {
        if (isFull())
        {
            cout << "Antrian penuh" << endl;
            return;
        }
        Node *newNode = new Node;
        newNode->data_128 = data_128;
        newNode->next = nullptr;
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

    // Untuk mengeluarkan data teller dari antrian
    void dequeue()
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

    // Untuk menampilkan semua data teller pada antrian
    void viewQueue()
    {
        cout << "Data antrian teller:" << endl;
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
                cout << pos++ << ". " << current->data_128 << endl;
                current = current->next;
            }
            // Jika masih tersisa ruang di antrian, tampilkan sebagai (kosong)
            for (int i = size; i < Maks_128; i++)
            {
                cout << i + 1 << ". (kosong)" << endl;
            }
        }
    }

    // Untuk menghitung semua antrian pada teller
    int countQueue()
    {
        return size;
    }

    // Untuk menghapus semua antrian
    void clearQueue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
};

int main()
{
    // Untuk inisialisasikan antrian
    Queue tellerQueue;
    // Untuk menambahkan data pada antrian
    tellerQueue.enqueue("Andi");
    tellerQueue.enqueue("Maya");
    // Untuk melihat semua data pada antrian
    tellerQueue.viewQueue();
    // Untuk menghitung semua data teller pada antrian
    cout << "Jumlah antrian = " << tellerQueue.countQueue() << endl;
    // Untuk mengeluarkan data pada antrian
    tellerQueue.dequeue();
    // Untuk melihat semua data pada antrian
    tellerQueue.viewQueue();
    // Untuk menghitung semua data teller pada antrian
    cout << "Jumlah antrian = " << tellerQueue.countQueue() << endl;
    // Untuk menghapus semua data pada antrian
    tellerQueue.clearQueue();
    // Untuk melihat semua data pada antrian
    tellerQueue.viewQueue();
    // Untuk menghitung semua data teller pada antrian
    cout << "Jumlah antrian = " << tellerQueue.countQueue() << endl;
    return 0;
}
