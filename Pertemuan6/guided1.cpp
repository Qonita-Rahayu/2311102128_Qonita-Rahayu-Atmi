#include <iostream>
using namespace std;

// Untuk menampung buku max 5
string arrayBuku[5];
int maksimal = 5, top = 0;

// Untuk mengecek apakah stack full atau tidak dan mengembalikan nilai top maksimal
bool isFull()
{
  return (top == maksimal);
}

// Untuk mengecek apakah stack kosong atau tidak
bool isEmpty()
{
  return (top == 0);
}

// Prosedur untuk menambahkan data baru ke dalam stack
void pushArrayBuku(string data)
{
  if (isFull())
  {
    // Stack penuh, tampilkan pesan
    cout << "Data telah penuh" << endl;
  }
  else
  {
    // Stack masih ada ruang, tambahkan data
    arrayBuku[top] = data;
    top++;
  }
}

// Prosedur untuk mengeluarkan data di stack
void popArrayBuku()
{
  if (isEmpty())
  {
    // Stack kosong, tampilkan pesan
    cout << "Tidak ada data yang bisa dihapus" << endl;
  }
  else
  {
    // Stack tidak kosong, hapus data terakhir
    arrayBuku[top - 1] = "";
    top--;
  }
}

// Prosedur untuk menampilkan data pada posisi tertentu dalam stack
void peekArrayBuku(int posisi)
{
  if (isEmpty())
  {
    // Stack kosong, tampilkan pesan
    cout << "Tidak ada data yang bisa dilihat" << endl;
  }
  else
  {
    // Stack tidak kosong, tampilkan data pada posisi tertentu
    int index = top;
    for (int i = 1; i < posisi; i++)
    {
      index--;
    }
    cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
  }
}

// Fungsi untuk mengembalikan jumlah data dalam stack
int countStack()
{
  return top;
}

// Prosedur untuk mengubah data pada posisi tertentu dalam stack
void changeArrayBuku(int posisi, string data)
{
  if (posisi > top)
  {
    // Posisi melebihi data yang ada, tampilkan pesan
    cout << "Posisi melebihi data yang ada" << endl;
  }
  else
  {
    // Posisi valid, ubah data pada posisi tertentu
    int index = top;
    for (int i = 1; i < posisi; i++)
    {
      index--;
    }
    arrayBuku[index] = data;
  }
}

// Prosedur untuk menghapus semua data dalam stack dan mengembalikan stack ke keadaan kosong
void destroyArrayBuku()
{
  for (int i = 0; i < top; i++)
  {
    arrayBuku[i] = "";
  }
  top = 0;
}

// Prosedur untuk mencetak semua data dalam stack dari atas ke bawah
void cetakArrayBuku()
{
  if (isEmpty())
  {
    // Stack kosong, tampilkan pesan
    cout << "Tidak ada data yang dicetak" << endl;
  }
  else
  {
    for (int i = top - 1; i >= 0; i--)
    {
      cout << arrayBuku[i] << endl;
    }
  }
}

int main()
{
  // untuk menambahkan data baru ke dalam stack
  pushArrayBuku("Kalkulus");
  pushArrayBuku("Struktur Data");
  pushArrayBuku("Matematika Diskrit");
  pushArrayBuku("Dasar Multimedia");
  pushArrayBuku("Inggris");

  // Untuk menampilkan semua data dalam stack
  cetakArrayBuku();
  cout << "\n";

  // Untuk mengecek apakah stack penuh atau tidak
  cout << "Apakah data stack penuh? " << isFull() << endl;
  // Untuk mengecek apakah stack kosong atau tidak
  cout << "Apakah data stack kosong? " << isEmpty() << endl;

  // Untuk menampilkan data pada posisi tertentu dalam stack
  peekArrayBuku(2);
  popArrayBuku();

  // Untuk mengecek banyaknya data
  cout << "Banyaknya data = " << countStack() << endl;

  // Untuk mengubah data pada posisi tertentu dalam stack
  changeArrayBuku(2, "Bahasa Jerman");
  cetakArrayBuku();

  cout << "\n";

  // Untuk menghapus semua data dalam stack dan mengembalikan stack ke keadaan kosong
  destroyArrayBuku();
  cout << "jumlah data setelah dihaopus:" << top << endl;
  cetakArrayBuku();

  return 0;
}