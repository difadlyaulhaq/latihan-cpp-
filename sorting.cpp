#include <iostream>
#include <conio.h>
using namespace std;

int data[10], data2[10];
int n;

int tukar(int a, int b) {
    int t;
    t = data[b];
    data[b] = data[a];
    data[a] = t;
    return 0;
}

int input() {
    cout << "Masukkan jumlah data: ";
    cin >> n;

    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << "Masukkan data ke-" << i + 1 << ": ";
        cin >> data[i];

        data2[i] = data[i];
    }
    cout << endl;
    return 0;
}

int tampil() {
    for (int i = 0; i < n; i++) {
        cout << "[" << data[i] << "]";
    }
    cout << endl;
    return 0;
}

int bubble_sort() {
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            if (data[j] < data[j - 1]) {
                tukar(j, j - 1);
            }
        }
        tampil();
    }
    cout << endl;
    return 0;
}

int selection_sort() {
    int i, j, posisi, tukar;
    for (i = 0; i < (n - 1); i++) {
        posisi = i;
        for (j = i + 1; j < n; j++) {
            if (data[j] < data[posisi]) {
                posisi = j;
            }
        }
        if (posisi != i) {
            tukar = data[i];
            data[i] = data[posisi];
            data[posisi] = tukar;
        }
        tampil();
    }
    cout << endl;
    return 0;
}

int main() {
    cout << "ALGORITMA BUBBLE SORT" << endl;
    cout << "----------------------" << endl;
    input();
    cout << "Proses bubble sort" << endl;
    tampil();
    bubble_sort();
    cout << "-------------------" << endl;
    cout << "Proses selection sort" << endl;
    selection_sort();
    getch();
    return 0;
}
