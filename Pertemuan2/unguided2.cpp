#include <iostream>
using namespace std;

int main()
{
    // variable untuk menampung inputan element dari user
    int element_128;
    cout << "Masukkan Jumlah Element Array : ";
    cin >> element_128;
    // array dengan element yang akan diinputkna user
    int arr[element_128][element_128][element_128];
    // Input elemen
    for (int y = 0; y < element_128; y++)
    {
        for (int z = 0; z < element_128; z++)
        {
            for (int j = 0; j < element_128; j++)
            {
                cout << "Input Array[" << y << "][" << z << "][" << j << "] = ";
                cin >> arr[y][z][j];
            }
        }
        cout << endl;
    }
    // Output Array
    for (int y = 0; y < element_128; y++)
    {
        for (int z = 0; z < element_128; z++)
        {
            for (int j = 0; j < element_128; j++)
            {
                cout << "Data Array[" << y << "][" << z << "][" << j << "] = " << arr[y][z][j] << endl;
            }
        }
    }
    cout << endl;
    // Tampilan array
    for (int y = 0; y < element_128; y++)
    {
        for (int z = 0; z < element_128; z++)
        {
            for (int j = 0; j < element_128; j++)
            {
                cout << arr[y][z][j] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}