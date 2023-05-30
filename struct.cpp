#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;
 struct Mahasiswa
{
    char NIM [10];
    char nama[20];
    float ipk ;
};

int main()
{
    Mahasiswa mhs;
    cout<<"masukan data anda"<<endl;
    cout<<"NIM : \n";
    cin>>mhs.NIM;
    cout<<"nama : \n";
    cin>>mhs.nama;
    cout<<"ipk :\n";
    cin>>mhs.ipk;

    cout<<"===data anda==="<<endl;
    cout<<"nim anda :"<<mhs.NIM<<endl;
    cout<<"nama anda: "<<mhs.nama<<endl;
    cout<<"ipk anda : "<<mhs.ipk<<endl;

    
    
    
}