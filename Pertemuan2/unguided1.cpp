#include <iostream>
using namespace std;

int main (){
    // variable untuk menampung panjang data array, data array, nomor genap, dan nomor ganjil
    int panjang_data_128, data_array_128, nomor_genap_128 = 0, nomor_ganjil_128 = 0;
    // input panjang data
    cout<<"Masukkan Jumlah Data : ";
    cin>> panjang_data_128;
    int array_128[panjang_data_128];
    // input data array
    for (int i = 0; i < panjang_data_128; i++){
        cout<<"Masukkan Data ke-"<<i<<" : ";
        cin>>data_array_128;
        array_128[i] = data_array_128;
    }
    // mencetak data array
    cout<<"Data Array : ";
    for (int i = 0; i < panjang_data_128; i++){
        cout<<array_128[i]<<" ";
    }
    cout << endl;
    // mencetak nomor genap
    cout<<"Nomor Genap : ";
    for (int i = 0; i < panjang_data_128; i++){
        if (array_128[i] % 2 == 0){
            cout<<array_128[i]<<", ";
            nomor_genap_128++;
        }
    }
    cout << endl;
    // mencetak nomor ganjil
    cout<<"Nomor Ganjil : ";
    for (int i = 0; i < panjang_data_128; i++){
        if (array_128[i] % 2 != 0){
            cout<<array_128[i]<<" ,";
            nomor_ganjil_128++;
        }
    }
}