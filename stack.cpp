#include <iostream>

using namespace std;

const int MAX_SIZE = 5;

class Stack {
private:
    int data[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack is full. Unable to push." << endl;
            return;
        }

        data[++top] = value;
        cout << "Pushed " << value << " to the stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Unable to pop." << endl;
            return;
        }

        int value = data[top--];
        cout << "Popped " << value << " from the stack." << endl;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. No element to peek." << endl;
            return -1;
        }

        return data[top];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack: ";
        for (int i = top; i >= 0; --i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void run() {
        int choice;
        int value;

        while (true) {
            cout << "Stack Menu:" << endl;
            cout << "1. Push" << endl;
            cout << "2. Pop" << endl;
            cout << "3. Peek" << endl;
            cout << "4. Display" << endl;
            cout << "5. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter the value to push: ";
                    cin >> value;
                    push(value);
                    break;
                case 2:
                    pop();
                    break;
                case 3:
                    value = peek();
                    if (value != -1) {
                        cout << "Top element: " << value << endl;
                    }
                    break;
                case 4:
                    display();
                    break;
                case 5:
                    cout << "Exiting..." << endl;
                    return;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }

            cout << endl;
        }
    }
};

int main() {
    Stack myStack;
    myStack.run();

    return 0;
}
