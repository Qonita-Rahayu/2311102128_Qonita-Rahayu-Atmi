#include <iostream>
#include <stack>
using namespace std;

string Pembalik_kata(string kalimat_128) {
    //inisialisasi stack
    stack<string> st;
    string kata = "";
    // memecah kata-kata
    for (size_t i = 0; i < kalimat_128.length(); i++) {
        // mengecek kalimat apakah ada spasi maka push ke stack
        if (kalimat_128[i] == ' ') {
            st.push(kata);
            kata = "";
        } else {
            kata += kalimat_128[i];
        }
    }
    // mengirimkan kata terakhir
    st.push(kata);
    // membuat kalimat terbalik
    string kalimatTerbalik_128 = "";
    // mengecek apakah stack tidak kosong
    while (!st.empty()) {
        string kataTerbalik_128 = "";
        // mengambil kata dari stack urutan paling ats
        string kata_awal = st.top();
        // membalik urutan kata 
        for (int i = kata_awal.length() - 1; i >= 0; i--) {
            kataTerbalik_128 += kata_awal[i];
        }
        // menambahkan kata ke variable kalimatTerbalik_128
        kalimatTerbalik_128 += kataTerbalik_128 + " ";
        st.pop();
    }
    // mengembalikan kalimat terbalik
    return kalimatTerbalik_128;
}
int main() {
    // input kalimat
    string kalimat_128;
    cout << "Masukkan Kalimat: ";
    getline(cin, kalimat_128);
    // mengeluarkan kalimat setelah diturunkan
    string kalimatTerbalik_128 = Pembalik_kata(kalimat_128);
    cout << "Hasil Kalimat Setelah Diturunkan: " << kalimatTerbalik_128 << endl;

    return 0;
}