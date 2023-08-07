#include <iostream>
#include <string>
using namespace std;
struct Matakuliah
{
   string nama;
   int sks;
   string nilai;
};
struct mahasiswa
{
    string nama;
    string nim;
    double ipk;
    Matakuliah mata_kuliah[5];
};
float hitungIPK(mahasiswa mhs)
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

int main(){
    int kuota;
    int numcourse;
    const int MAX_MK = 5;
    cout<<"Program KHS mahasiswa"<<endl;
    cout<<"masukan jumlah mahasiswa :";
    cin>>kuota;
    cout<<"---------------------------";
    do {
        cout << "\nMasukkan jumlah mata kuliah (maksimal " << MAX_MK << "): ";
        cin >> numcourse;
    } while (numcourse < 1 || numcourse > MAX_MK);
    cout<<"---------------------------";

    mahasiswa mhs[kuota];
    for (int i = 0; i < kuota; i++)
    {
        cout<<"\nmahasiswa ke = "<<i+1<<endl;
        
        cout<<"masukan nama :";
        cin.ignore();
        getline(cin,mhs[i].nama);
        
        cout<<"masukan NIM :";
        cin.ignore();
        getline(cin,mhs[i].nim);

            for (int j = 0; j <numcourse; j++)
            {
                cout<<"---------------------------";
                cout<<"\nMatakuliah ("<<i+1<<")"<<endl;
                cout<<"nama matakuliah :";
                cin.ignore();
                getline(cin,mhs[i].mata_kuliah[j].nama);
                cout<<"bobot kuliah = ";
                cin>>mhs[i].mata_kuliah[j].sks;
                cout<<"nilai (A-E): ";
                cin.ignore();
                getline(cin,mhs[i].mata_kuliah[j].nilai);
                cout<<"---------------------------";
        }
    }
            for (int i = 0; i < kuota; i++)
            {
                cout<<"mahasiswa ke - "<<i+1<<endl;
                cout<< "nama :"<<mhs[i].nama<<endl;
                cout << "NIM :" <<mhs[i].nim<<endl;

                for (int j = 0; j < 5; j++) {
                    if (mhs[i].mata_kuliah[j].nama != "") {
                     cout << mhs[i].mata_kuliah[j].nama<< " " << mhs[i].mata_kuliah[j].sks << " " << mhs[i].mata_kuliah[j].nilai << endl;
            }
        }
        cout << "IPK: " << hitungIPK(mhs[i]) << endl;
            }
    
}