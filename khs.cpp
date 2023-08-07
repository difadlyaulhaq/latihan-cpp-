#include <iostream>
#include <string>

using namespace std;

struct MataKuliah {
    string kode;
    string nama;
    int sks;
    string nilai;
};

struct Mahasiswa {
    string nim;
    string nama;
    MataKuliah matkul[5];
};

float hitungIPK(Mahasiswa mhs) {
    float totalBobot = 0;
    int totalSKS = 0;
    for (int i = 0; i < 5; i++) {
        if (mhs.matkul[i].kode != "") {
            int bobot = mhs.matkul[i].sks * (mhs.matkul[i].nilai == "A" ? 4 :
                                             mhs.matkul[i].nilai == "B" ? 3 :
                                             mhs.matkul[i].nilai == "C" ? 2 :
                                             mhs.matkul[i].nilai == "D" ? 1 : 0);
            totalBobot += bobot;
            totalSKS += mhs.matkul[i].sks;
        }
    }
    if (totalSKS > 0) {
        return totalBobot / totalSKS;
    } else {
        return 0;
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;
    Mahasiswa mhs[n];
    for (int i = 0; i < n; i++) {
        cout << "Mahasiswa ke-" << i+1 << endl;
        cout << "NIM: ";
        cin >> mhs[i].nim;
        cout << "Nama: ";
        getline(cin >> ws, mhs[i].nama);
        for (int j = 0; j < 5; j++) {
            cout << "Mata kuliah ke-" << j+1 << endl;
            cout << "Kode: ";
            cin >> mhs[i].matkul[j].kode;
            cout << "Nama: ";
            getline(cin >> ws, mhs[i].matkul[j].nama);
            cout << "Bobot SKS: ";
            cin >> mhs[i].matkul[j].sks;
            cout << "Nilai (A-E): ";
            cin >> mhs[i].matkul[j].nilai;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << "KHS " << mhs[i].nim << " " << mhs[i].nama << endl;
        for (int j = 0; j < 5; j++) {
            if (mhs[i].matkul[j].kode != "") {
                cout << mhs[i].matkul[j].kode << " " << mhs[i].matkul[j].nama << " "
                     << mhs[i].matkul[j].sks << " " << mhs[i].matkul[j].nilai << endl;
            }
        }
        cout << "IPK: " << hitungIPK(mhs[i]) << endl;
    }
    return 0;
}