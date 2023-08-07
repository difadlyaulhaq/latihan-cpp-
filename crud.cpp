#include <iostream>
using namespace std;
int main(){
    struct book
    {
        int numbook;
        string namapeminjam;
        int tanggalpeminjaman;
    };
    int choice;
    cout<<"selamat datang di program peminjaman buku,silahkan pilih menu berikut"<<endl;
    cout<<"*** (1)meminjam buku ***\n";
    cout<<"*** (2) buku yang tidak tersedia***\n";
    cout<<"*** (3)exit***\n";
    cin>>choice;
    switch (choice)
    {
    case 1:
        
        break;
    case 2:
    break;
    case 3:
            cout<<"====exit====";
    default:
    cout<<"pilihlah angka yang ada dimenu!!!"<<endl;
        break;
    }
}
