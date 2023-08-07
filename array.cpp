#include <iostream>
using namespace std;
int main()
{
    int size;
    int *array;// pada tipe data ini array akan dipindah kan pada 
    int min;
    
    cout<<"masukan jumlah array yang akan diolah ";
    cin>>size;

    array = new int [size];
    for (int i = 0; i < size; i++)
    {
            cout<<" nilai array ke#"<<i+1<<" = ";
            cin>>array[i];
    }
    min = array [0];
    for (int i = 0; i < size; i++)
    {
        if (array[i] < min) {
        min = array[i];
    }
    }
        cout<<"nilai yang terkecil dari array diatas = "<<min;
            delete[] array;

            return 0;
}
