#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Data {
    string nama;
    string alamat;
    string telepon;
};

void tambahData();
void tampilkanData();
void ubahData();
void hapusData();

int main() {
    int pilihan;

    do {
        cout << "=== Program CRUD dengan Akses File ===" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Tampilkan Data" << endl;
        cout << "3. Ubah Data" << endl;
        cout << "4. Hapus Data" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahData();
                break;
            case 2:
                tampilkanData();
                break;
            case 3:
                ubahData();
                break;
            case 4:
                hapusData();
                break;
            case 0:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    } while (pilihan != 0);

    return 0;
}

void tambahData() {
    Data data;
    cout << "=== Tambah Data ===" << endl;
    cout << "Nama: ";
    cin.ignore();
    getline(cin, data.nama);
    cout << "Alamat: ";
    getline(cin, data.alamat);
    cout << "Telepon: ";
    getline(cin, data.telepon);

    ofstream file("data.txt", ios::app);
    if (file.is_open()) {
        file << data.nama << "|" << data.alamat << "|" << data.telepon << endl;
        file.close();
        cout << "Data berhasil ditambahkan." << endl;
    } else {
        cout << "Gagal membuka file." << endl;
    }
}

void tampilkanData() {
    cout << "=== Tampilkan Data ===" << endl;

    ifstream file("data.txt");
    if (file.is_open()) {
        string line;
        int count = 1;
        while (getline(file, line)) {
            cout << "Data #" << count << endl;
            cout << "Nama: " << line.substr(0, line.find("|")) << endl;
            line = line.substr(line.find("|") + 1);
            cout << "Alamat: " << line.substr(0, line.find("|")) << endl;
            line = line.substr(line.find("|") + 1);
            cout << "Telepon: " << line << endl;
            cout << endl;
            count++;
        }
        file.close();
    } else {
        cout << "Gagal membuka file." << endl;
    }
}

void ubahData() {
    int nomor;
    cout << "=== Ubah Data ===" << endl;
    cout << "Nomor Data yang ingin diubah: ";
    cin >> nomor;

    ifstream fileIn("data.txt");
    ofstream fileOut("temp.txt", ios::app);
    if (fileIn.is_open() && fileOut.is_open()) {
        string line;
        int count = 1;
        while (getline(fileIn, line)) {
            if (count == nomor) {
                Data data;
                cout << "Nama baru: ";
                cin.ignore();
                getline(cin, data.nama);
                cout << "Alamat baru: ";
                getline(cin, data.alamat);
                cout << "Telepon baru: ";
                getline(cin, data.telepon);
                fileOut << data.nama << "|" << data.alamat << "|" << data.telepon << endl;
                cout << "Data berhasil diubah." << endl;
            } else {
                fileOut << line << endl;
            }
            count++;
        }
        fileIn.close();
        fileOut.close();

        remove("data.txt");
        rename("temp.txt", "data.txt");
    } else {
        cout << "Gagal membuka file." << endl;
    }
}

void hapusData() {
    int nomor;
    cout << "=== Hapus Data ===" << endl;
    cout << "Nomor Data yang ingin dihapus: ";
    cin >> nomor;

    ifstream fileIn("data.txt");
    ofstream fileOut("temp.txt", ios::app);
    if (fileIn.is_open() && fileOut.is_open()) {
        string line;
        int count = 1;
        while (getline(fileIn, line)) {
            if (count != nomor) {
                fileOut << line << endl;
            } else {
                cout << "Data berhasil dihapus." << endl;
            }
            count++;
        }
        fileIn.close();
        fileOut.close();

        remove("data.txt");
        rename("temp.txt", "data.txt");
    } else {
        cout << "Gagal membuka file." << endl;
    }
}
