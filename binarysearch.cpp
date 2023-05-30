#include <iostream>
using namespace std;

int main() {
    int m;
    int arr[]{1, 2, 5, 7, 8, 9, 9, 11, 15, 16, 20};
    int l{0};
    int r{10};
    cout<<" data yang tersimpan \n";
    for (int i = 0; i < r; i++)
    {
        cout<<arr[i]<<"  ";
    }
    char choice = 'y';

   while (choice == 'y' || choice == 'Y')
   {
    int x;
    cout <<"\nmasukan nilai yang akan anda cari : ";
    cin>>x;
        bool found = false;
    while (l <= r && !found) {
        m = l + (r - 1) / 2;
        if (x == arr[m]) {
            found = true;
            cout << "\n Data ditemukan ke- " << m << endl;
        } else if (x < arr[m]) {
            r = m - 1;
        } else if (x > arr[m]) {
            l = m + 1;
        }
    }
        if (!found)
        {
            cout<<"\n Nilai tidak ditemukan dalam array"<<endl;
        }
        cout<<"ingin cari lagi ?(y/n)";
        cin>>choice;

   }
    
    


    return 0;
}
