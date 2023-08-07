#include <iostream>
using namespace std;

const int maks = 5;
string book[maks];
int top = 0;

bool isFull() {
    if (top == maks) {
        return true;
    }
    else {
        return false;
    }
}

bool isEmpty() {
    if (top == 0) {
        return true;
    }
    else {
        return false;
    }
}

void pushArray(string data) {
    if (isFull()) {
        cout << "data anda penuh";
    }
    else {
        book[top] = data;
        top++;
    }
}

void popArray() {
    if (isEmpty()) {
        cout << "data kosong" << endl;
    }
    else {
        book[top - 1] = "";
        top--;
    }
}

void displayArray() {
    if (isEmpty()) {
        cout << "data kosong" << endl;
    }
    else {
        cout << "Data stack array :" << endl;
        cout << "-------------------" << endl;
        for (int i = maks - 1; i >= 0; i--) {
            if (book[i] != "") {
                cout << "stack " << i << ": " << book[i] << endl;
            }
        }
        cout << "\n" << endl;
    }
}

void destroyArray() {
    for (int i = 0; i < top; i++) {
        book[i] = "";
    }
    top = 0;
}

int main() {
    pushArray("Delapan");
    displayArray();

    pushArray("sembilan");
    pushArray("tiga");
    displayArray();

    popArray();
    displayArray();

    pushArray("lima");
    pushArray("enam");
    pushArray("tujuh");
    displayArray();

    popArray();
    displayArray();

    popArray();
    displayArray();

    cout << "apakah data full " << isFull() << endl;
    cout << "apakah data kosong " << isEmpty() << endl;
    destroyArray();

    cout << "setelah diclear " << endl;
    cout << "apakah data full " << isFull() << endl;
    cout << "apakah data kosong " << isEmpty() << endl;

    return 0;
}
