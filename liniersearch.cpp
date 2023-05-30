#include <iostream>
using namespace std;

int main(){
    int x = 10;
    int arr[]{5,9,2,7,8,1,6};

    bool found(false);
    for (int i = 0; i < 7; i++)
    {
        if (x == arr[i])
        {
            found = true ;
            cout<<"data ditemukan pada indeks ke - "<<i<<endl;
            break;
        }else if (x != arr[i])
        {
            found = false;
             cout<<"data tidak ditemukan di array"<<endl;
            break;
        }
    }
}
