#include <iostream>
#include <string>
using namespace std;

string reverseWord(const string& word) {
   
    int length = word.length();
    int *start = word;

    for (int i = length - 1; i >= 0; i--) {
       
    }

   
}

int main() {
    string word;
    cout << "Enter a word: ";
    cin >> word;

    string reversed = reverseWord(word);
    cout << "Reversed word: " << reversed << endl;

    return 0;
}