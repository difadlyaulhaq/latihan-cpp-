#include <iostream>
using namespace std;
int main()
{
int *num_addr;//pointer
int miles, dist;
miles = 22;
num_addr = &miles;//miles disimpan ke pointer
cout << "Alamat yang disimpan di dalam num_addr adalah " << num_addr << endl;
cout << "Nilai yang ditunjuk oleh num_addr adalah " << *num_addr << endl;
dist = 158;
num_addr = &dist;
cout << "Alamat yang disimpan di dalam num_addr adalah " << num_addr << endl;
cout << "Nilai yang ditunjuk oleh num_addr adalah " << *num_addr << endl;
}