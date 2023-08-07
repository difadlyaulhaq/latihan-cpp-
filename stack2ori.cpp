 #include <iostream>
using namespace std;

const int MAX_stack = 5;

struct Stack {
    int top;
    int data[MAX_stack];
};

Stack stack;

void initiate();
void push(int data);
void pop();
void clear();
bool isEmpty();
bool isFull();
void print();

void initiate() {
    stack.top == -1;
}

void push(int data) {
    stack.top++;
    stack.data[stack.top]= data;
    cout<<"data berhasil ditambahkan "<<endl<<endl;
      
}
void pop() {
    
    int data = stack.data[stack.top];
   stack.top--;
   cout<<"data"<<data<<"sudah dihapus"<<endl<<endl;
       
}

void clear() {
    stack.top = -1;
    cout << "Stack berhasil dikosongkan." << endl<<endl;
    
}

bool isEmpty() {
    return (stack.top == -1);
}

bool isFull() {
    return (stack.top == MAX_stack-1);
}

void print() {
    if (isEmpty()) {
        cout << "Stack masih kosong." << endl;
    }
    else {
        cout << "Data pada stack:" << endl;
        for (int i = stack.top; i >= 0; i--) {
            cout << stack.data[i] << endl;
        }
    }
}

int main(){
    initiate();

    int menu;
    int data;

    do {
        cout<<"NAMA : Difa dlyaul haq"<<endl;
        cout<<"NIM : 22.61.0234"<<endl;
        cout<<endl;
        cout << "<<< PILIHAN MENU STACK <<<" << endl << endl;
        cout << "1. menambahkan item stack" << endl;
        cout << "2. menghapus item stack" << endl;
        cout << "3. menampilkan stack " << endl;
        cout << "4. mengosongkan stack" << endl;
        cout << "5. selesai" << endl << endl;

        cout << "Masukkan pilihan Anda: ";
        cin >> menu;

        switch (menu) {
            case 1:
                cout << "Masukkan data: ";
                cin >> data;
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                print();
                break;
            case 4:
                clear();
                break;
            case 5:
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (menu != 5);

    cout << endl;

    return 0;
}