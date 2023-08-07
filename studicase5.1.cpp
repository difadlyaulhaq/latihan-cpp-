#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Antrian {
private:
    vector<string> data;
    int top;
    int maksElemen;

public:
    // Konstruktor
    Antrian(int size) {
        depan = -1;
        maksElemen = size;
        data.resize(size); // Ukuran vector
    }

    // Memasukkan data ke antrian
    // Nilai balik tidak ada
    void insert(string x) {
        int posisiBelakang;
        // Geser belakang ke posisi berikutnya
        if (belakang == maksElemen )
            posisiBelakang = 1; // antrian penuh dan belakang akan dikembalikan ke posisi awal
        else
            posisiBelakang = belakang + 1;

        // Cek belakang apa sama dengan Depan
        if (posisiBelakang == depan)
            cout << "Antrian penuh" << endl;
        else {
            belakang = posisiBelakang;
            // Masukkan data
            data[belakang] = x;
        }
    }

    string remove() {
        if (empty()) {
            cout << "Antrian kosong" << endl;
            return "";
        }

        if (depan == maksElemen)
            depan = 0;
        else
            depan= depan +1;

        return data[depan];
    }

    bool empty() {
        if (depan == belakang)
            return true;
        else
            return false;
    }

    int size() {
        if (belakang >= depan)
            return belakang - depan;
        else
            return maksElemen - (depan + belakang);
    }

   void display() {
    if (empty()) {
        cout << "(Antrian kosong)" << endl;
    } else {
        cout << "Isi dari antrian adalah: " << endl;
        int i = depan;
        while (i != belakang) {
            cout << data[i] << endl;
            i = (i + 1) % maksElemen;
        }
    }
}

     // Method getter
    int getDepan() { return depan; }
    int getBelakang() { return belakang; }
    string at(int idx) { return data[idx]; }
};

int main() {
    int ukuran = 10;
    Antrian daftar(ukuran); // Buat objek

    // Masukkan 5 buah nama
    daftar.insert("Aman");
    daftar.insert("Budi");
    daftar.insert("Caca");
    daftar.insert("Didi");
    daftar.insert("Edi");

    daftar.display();
    cout << "Ukuran antrian: " << daftar.size() << endl;
    
    cout << "\nData yang dihapus pertama: " << daftar.remove() << endl;
    cout << "Data yang dihapus kedua: " << daftar.remove() << endl;
    cout << "\nUkuran data setelah dihapus = "<<daftar.size() << endl<<endl;

    
    daftar.insert("Kania");
    daftar.insert("senia");
    daftar.insert("difa");
    daftar.display();
    cout << "Ukuran antrian saat ini : " << daftar.size() << endl;

}