#include <iostream>
using namespace std;

int main() {
    int SIZE ; // konstanta ukuran array
    int numbers[SIZE]; // deklarasi array of integers dengan ukuran SIZE
    int smallest; // variabel untuk menampung nilai terkecil dalam array
        cout<<"input jumlah array yang akan dimasukan";
        cin>>SIZE;
    // meminta input dari pengguna dan menyimpannya dalam array
    for (int i = 0; i < SIZE; i++) {
        cout << "Masukkan angka ke-" << i+1 << ": ";
        cin >> numbers[i];
    }

    // mencari nilai terkecil dalam array
    smallest = numbers[0];
    for (int i = 1; i < SIZE; i++) {
        if (numbers[i] < smallest) {
            smallest = numbers[i];
        }
    }

    // menampilkan nilai terkecil dalam array
    cout << "Nilai terkecil dalam array: " << smallest << endl;

    return 0;
}




