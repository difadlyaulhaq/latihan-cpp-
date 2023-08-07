#include <iostream>
using namespace std;

int main(){
cout<<"NAMA : Difa Dlyaul Haq"<<endl;
cout<<"NIM : 22.61.0234"<<endl;
        int umur[] = {21,22,23,24,25};
        int *ptrUmur = umur;
    for (int i = 0; i < 5 ; i++)
    {
        cout<<"Alamat umur ["<<i<<"] = "<<&umur[i]<<endl;
    }
    
    cout<<"nilai ptrUmur = "<<ptrUmur<<" sama dengan nilai umur[0]("<<&umur[0]<<")"<<endl;

    ptrUmur +=3;
    cout<<"nilai ptrUmur = "<<ptrUmur<<" sama dengan nilai umur[3]("<<&umur[3]<<")"<<endl;

    ptrUmur -=2;
    cout<<"nilai ptrUmur = "<<ptrUmur<<" sama dengan nilai umur[1]("<<&umur[1]<<")"<<endl;


}