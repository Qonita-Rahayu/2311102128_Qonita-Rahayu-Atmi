#include <iostream>
using namespace std;
int main()
{
    // variable untuk menampung panjang array, input pilih menu, nilai maksimum, minimum, dan total
    int panjang_array_128, menu_128, maksimum_128, minimum_128, total_128;
    double rata_128;

    // input panjang array
    cout << "Masukkan panjang array: ";
    cin >> panjang_array_128;
    int array_128[panjang_array_128];
    cout << "masukan panjang array : "<< panjang_array_128 << " angka"<< endl;
    for (int i = 0; i < panjang_array_128; i++)
    {
        cout << "array ke-" << (i) << ": ";
        cin >> array_128[i];
    }
    // perulangan untuk menu pilih 
    do
    {
        // input pilih menu
        cout << "Pilih menu: " << endl;
        cout << "1. Nilai maksimum" << endl;
        cout << "2. Nilai minimum" << endl;
        cout << "3. Nilai rata-rata" << endl;
        cout << "4. Keluar" << endl;
        cout << "masukan pilihan menu :";
        // input pilih menu
        cin >> menu_128;
        switch (menu_128)
        {
            // case untuk mencari nilai angka maksimum pada data array
        case 1:
            maksimum_128 = array_128[0];
            for (int i = 0; i < panjang_array_128; i++)
            {
                if (array_128[i] > maksimum_128)
                {
                    maksimum_128 = array_128[i];
                }
            }
            //menampilkan nilai maksimum 
            cout << "Nilai maksimum adalah " << maksimum_128 << endl;
            break;

            // case untuk mencari nilai angka minimum pada data array
            case 2:
            minimum_128 = array_128[0];
            for (int i = 0; i < panjang_array_128; i++)
            {
                if (array_128[i] < minimum_128)
                {
                    minimum_128 = array_128[i];
                }
            }
            cout << "Nilai minimum adalah " << minimum_128 << endl;
            break;

            // case untuk mencari nilai rata rata pada data array
            case 3:
            total_128 = 0;
            for (int i = 0; i < panjang_array_128; i++)
                total_128 += array_128[i];
                rata_128 = static_cast<double>(total_128) / panjang_array_128;
                cout << "Rata-rata dari array adalah: " << rata_128 << endl;
                break;
            cout << "Nilai rata rata adalah : " << total_128 << endl;
            break;
        
        default:
            break;
        }
    } while (menu_128 !=4);
    
    return 0;
}