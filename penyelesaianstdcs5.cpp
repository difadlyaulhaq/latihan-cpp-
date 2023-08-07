#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Stack {
private:
    vector<string> data;
    int top;
    int maxSize;

public:
    Stack(int size) {
        top = -1;
        maxSize = size;
        data.resize(size);
    }

    void push(string x) {
        if (top == maxSize - 1) {
            cout << "Stack penuh" << endl;
        } else {
            top++;
            data[top] = x;
        }
    }

    string pop() {
        if (top == -1) {
            cout << "Stack kosong" << endl;
            return "";
        } else {
            string popped = data[top];
            top--;
            return popped;
        }
    }

    bool empty() {
        if (top == -1)
            return true;
        else
            return false;
    }

    bool full() {
        if (top == maxSize - 1)
            return true;
        else
            return false;
    }

    int size() {
        return top + 1;
    }

    void display() {
        if (empty()) {
            cout << "Stack kosong" << endl;
        } else {
           
            for (int i = top; i >= 0; i--) {
                cout << data[i] << endl;
            }
        }
    }
};

int main() {

    int ukuran = 10;
    Stack stack(ukuran);
    cout<<"nama : difa dlyaul haq"<<endl;
    cout<<"NIM : 22.61.0234"<<endl<<endl;
    
    
    stack.push("Aman");
    stack.push("Budi");
    stack.push("Caca");
    stack.push("Didi");
    stack.push("Edi");
    
    cout << "Isi dari stack adalah: " << endl;
    stack.display();
    cout<<endl;
    cout << "Ukuran stack awal : " << stack.size() << endl;
    cout<<endl;
    cout << "Data yang di-pop: " << stack.pop() << endl;
    cout << "Data yang di-pop: " << stack.pop() << endl;
    cout<<endl;
    cout << "Ukuran stack setelah di pop : " << stack.size() << endl;
    stack.push("kania");
    stack.push("senia");
    stack.push("difa");
     cout << "Isi dari stack setelah insert 3 data: " << endl;
    stack.display();
    cout<<endl;
    cout << "Ukuran stack setelah di insert : " << stack.size() << endl;

    return 0;
}
