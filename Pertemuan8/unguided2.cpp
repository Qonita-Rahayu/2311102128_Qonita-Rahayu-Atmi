#include <iostream>

using namespace std;

int main()
{
    // variable menampung kalimat dan menghitung total huruf vokal
    string kalimat_128;
    int countVocal_128 = 0;

    // Input huruf vokal
    cout << "=============================================\n"; 
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat_128);
    cout << "=============================================\n"; 

    // perulangan untuk mencocokan huruf vokal pada kata yang di inputkan
    for (int i = 0; i < kalimat_128.length(); i++)
    {
        if (kalimat_128[i] == 'a' || kalimat_128[i] == 'i' || kalimat_128[i] == 'u' || kalimat_128[i] == 'e' || kalimat_128[i] == 'o' ||
        kalimat_128[i] == 'A' || kalimat_128[i] == 'I' || kalimat_128[i] == 'U' || kalimat_128[i] == 'E' || kalimat_128[i] == 'O')
        {
            countVocal_128++;
        }
    }

    // menampilkan jumlah total huruf vokal
    cout << "Jumlah huruf vokal dalam kalimat yaitu: " << countVocal_128 << endl;
    cout << "=============================================\n"; 

    return 0;
}