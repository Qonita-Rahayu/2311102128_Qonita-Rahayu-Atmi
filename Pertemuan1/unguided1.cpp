#include <iostream>
#include <iomanip>

using namespace std;

// Fungsi untuk menampilkan menu
void printoperasi_128() {
    cout << "Pilih op_128erasi: " << endl;
    cout << "1. Penjumlahan" << endl;
    cout << "2. Pengurangan" << endl;
    cout << "3. Perkalian" << endl;
    cout << "4. Pembagian" << endl;  
}

// Fungsi untuk menyelesaikan operasi
int kalkulator_128(int num1_128, int num2_128, char op_128) {

    // Percabangan untuk menentukan operasi
    switch (op_128) {
        case '+':
            return num1_128 + num2_128;
        case '-':
            return num1_128 - num2_128;
        case '*':
            return num1_128 * num2_128;
        case '/':
            return num1_128 / num2_128;
        default:
            cout << "Error! operasi tidak valid." << endl;
            return 0;
    }
}

// Fungsi utama
int main() {
    int num1_128, num2_128;
    char op_128;

    // Input angka pertama dan kedua
    cout << "Masukkan angka pertama: ";
    cin >> num1_128;
    cout << "Masukkan angka kedua: ";
    cin >> num2_128;

    // Menampilkan menu operasi operator logika
    printoperasi_128();

    // Input operasi
    cout << "Masukkan operasi: ";
    cin >> op_128;

    // Cetak hasil operasi
    cout << "Hasil: " << kalkulator_128(num1_128, num2_128, op_128) << endl;

    return 0;
}



