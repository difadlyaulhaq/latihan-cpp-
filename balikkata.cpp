#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cout << "Masukkan sebuah string: ";
    getline(cin, str);

    int n = str.length();

    for (int i = 0; i < n/2; i++) {
        swap(str[i], str[n-i-1]);
    }

    cout << "String setelah dibalik: " << str << endl;

    return 0;
}
