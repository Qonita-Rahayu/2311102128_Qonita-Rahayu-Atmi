#include <iostream>
#include <array>
#include <map>
using namespace std;

// array untuk menampung data nilai
int nilai_128[5] = {10, 20, 30, 40, 50};

// map untuk menampung data kota
// insert data kota dengan key angka 1 sampai 5 dengan value kota
map<int, string> kota_128 = {
    {1, "Jakarta"},
    {2, "Bandung"},
    {3, "Bogor"},
    {4, "Depok"},
    {5, "Bekasi"}};
int main()
{
    // menampilkan array data nilai
    // menampilkan array nilai dengan index 0 sampai 4
    cout <<endl;
    cout << "menampilkan array nilai dengan index 0 sampai 4"<<endl;
    cout << "nilai pertama: " << nilai_128[0] << endl;
    cout << "nilai kedua: " << nilai_128[1] << endl;
    cout << "nilai ketiga: " << nilai_128[2] << endl;
    cout << "nilai keempat: " << nilai_128[3] << endl;
    cout << "nilai kelima: " << nilai_128[4] << endl;

    // map menampilkan data koata
    // menampilkan map kota dengan key angka 1 sampai 5 dengan value kota  
    cout <<endl;
    cout <<"menampilkan map kota dengan key angka 1 sampai 5 dengan value kota  "<< endl;
    cout << "kota pertama: " << kota_128[1] << endl;
    cout << "kota kedua: " << kota_128[2] << endl;
    cout << "kota ketiga: " << kota_128[3] << endl;
    cout << "kota keempat: " << kota_128[4] << endl;
    cout << "kota kelima: " << kota_128[5] << endl;
    return 0;
}