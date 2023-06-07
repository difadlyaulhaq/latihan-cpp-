#include <iostream>
using namespace std;

const int MAX_STACK = 5;

struct Stack
{
    int top;
    string data[MAX_STACK];
};

Stack tumpuk;

void initiate()
{
    tumpuk.top = -1;
}

bool isFull()
{
    return tumpuk.top == MAX_STACK - 1;
}

bool isEmpty()
{
    return tumpuk.top == -1;
}

void Push(const string& DATA)
{
    if (isFull())
    {
        cout << "Stack is full." << endl;
    }
    else
    {
        tumpuk.top++;
        tumpuk.data[tumpuk.top] = DATA;
        cout << "Pushed " << DATA << " onto the stack." << endl;
    }
}

void pop()
{
    if (isEmpty())
    {
        cout << "Stack is empty." << endl;
    }
    else
    {
        cout << "Data popped: " << tumpuk.data[tumpuk.top] << endl;
        tumpuk.data[tumpuk.top] = "";
        tumpuk.top--;
    }
}

void display()
{
    if (isEmpty())
    {
        cout << "Stack is empty." << endl;
    }
    else
    {
        cout << "Stack data: " << endl;
        for (int i = tumpuk.top; i >= 0; i--)
        {
            cout << tumpuk.data[i] << endl;
        }
    }
}

void peek()
{
    if (isEmpty())
    {
        cout << "Stack is empty." << endl;
    }
    else
    {
        cout << "Top of the stack: " << tumpuk.data[tumpuk.top] << endl;
    }
}

int main()
{
    initiate();
    Push("Data 1");
    Push("Data 2");
    Push("Data 3");
    pop();
    peek();
    display();

    return 0;
}
