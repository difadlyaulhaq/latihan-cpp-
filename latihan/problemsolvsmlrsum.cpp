#include <iostream>
#include <vector>
using namespace std;

int main(){
    int i;
    int n ;
    vector <int> arr (n);
    vector <int> answer(n);
    int sum = 0;
    
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j]<arr[i])
            {
                sum += arr[j];
            }
        }
        answer[i] = sum;
    }
    
    for (int i = 0; i < n; i++)
    {
       cout<<answer[i]<<" ";
    }
    return 0;
}
