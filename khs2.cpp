#include <iostream>
#include <string>
using namespace std;

struct Matakuliah
{
    string nama;
    int sks;
    string nilai;
};

struct Mahasiswa
{
    string nama;
    string nim;
    double ipk;
    Matakuliah mata_kuliah[5];
};

float hitungIPK(Mahasiswa mhs)
{
    float totalbobot = 0;
    int totalsks = 0;
    for (int i = 0; i < 5; i++)
    {
        if (mhs.mata_kuliah[i].nama != "")
        {
            int bobot = mhs.mata_kuliah[i].sks * (mhs.mata_kuliah[i].nilai == "A" ? 4 :
                                                  mhs.mata_kuliah[i].nilai == "B" ? 3 :
                                                  mhs.mata_kuliah[i].nilai == "C" ? 2 :
                                                  mhs.mata_kuliah[i].nilai == "D" ? 1 : 0);
            totalbobot += bobot;
            totalsks += mhs.mata_kuliah[i].sks;
        }
    }
    if (totalsks > 0)
    {
        return totalbobot / totalsks;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int kuota;
    int numcourse;
    const int MAX_MK = 5;
    cout << "Program KHS mahasiswa" << endl;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> kuota;
    cout << "---------------------------" << endl;
    do
    {
        cout << "Masukkan jumlah mata kuliah (maksimal " << MAX_MK << "): ";
        cin >> numcourse;
    } while (numcourse < 1 || numcourse > MAX_MK);
    cout << "---------------------------" << endl;

    Mahasiswa mhs[kuota];
    for (int i = 0; i < kuota; i++)
    {
        cout << "\nMahasiswa ke-" << i + 1 << endl;

        cout << "Masukkan nama: ";
        cin.ignore();
        getline(cin, mhs[i].nama);

        cout << "Masukkan NIM: ";
        getline(cin, mhs[i].nim);

        for (int j = 0; j < numcourse; j++)
        {
            cout << "---------------------------" << endl;
            cout << "Matakuliah (" << j + 1 << ")" << endl;
            cout << "Nama matakuliah: ";
            getline(cin, mhs[i].mata_kuliah[j].nama);
            cout << "Bobot kuliah: ";
            cin >> mhs[i].mata_kuliah[j].sks;
            cout << "Nilai (A-E): ";
            cin.ignore();
            getline(cin, mhs[i].mata_kuliah[j].nilai);
        }
        mhs[i].ipk = hitungIPK(mhs[i]);
    }

    cout << "---------------------------" << endl;
    cout << "Hasil: " << endl;
    for (int i = 0; i < kuota; i++)
    {
        cout << "Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama: " << mhs[i].nama << endl;
        cout << "NIM: " << mhs[i].nim << endl;
        cout << "IPK: " <<mhs[i].ipk<<endl;
    }
