#include <iostream>
using namespace std;
int main(){
    int x=6;
   int* y=&x;
cout << y << '\n';
y++;
cout << y << '\n';
}