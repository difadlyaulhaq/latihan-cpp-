#include <iostream>
#include <string.h>
using namespace std;
int main(){
cout<<"NAMA : Difa Dlyaul Haq"<<endl;
cout<<"NIM : 22.61.0234"<<endl;
 char kampus[] = "STMIK AMIKOM";
 int len = strlen(kampus);
 for (int i=0, j=len-1; i<j; i++, j--)
 {
    char temp = kampus[i];
    kampus[i] = kampus[j];
    kampus[j] = temp;
    
 }
 cout<< " STIMIK AMIKOM jika tidak dikembalikan maka menjadi  "<<kampus<<endl;
 

}