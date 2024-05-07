#include <iostream>
#include <stack>
#include <string>
using namespace std;

// fungsi untuk mengecek apakah sebuah kalimat merupakan palindrom 
bool Palindrom(string kata_128)
{
    // Inisialisasi stack
    stack<char> stack;
    // Memecah kalimat menjadi kata-kata
    for (char i : kata_128)
    {
        stack.push(i);
    }
    // Memeriksa apakah kalimat tersebut merupakan palindrom
    for (char j : kata_128)
    {
        // percabangan apakah kata pada top tidak sama dengan j atau sama
        if (stack.top() != j)
        {
            return false;
        }
        stack.pop();
    }
    return true;
}

int main()
{
    // input kalimat
    string input;
    cout << "Masukan Kalimat: ";
    getline(cin, input);
    // mengecek apakah kalimat tersebut merupakan palindrom
    if (Palindrom(input))
    {
        cout << "Kalimat tersebut adalah : Palindrom" << endl;
    }
    else
    {
        cout << "Kalimat tersebut adalah bukan : Palindrom" << endl;
    }

    return 0;
}