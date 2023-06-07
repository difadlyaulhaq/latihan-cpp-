#include <iostream>
using namespace std;

const int MAX = 5;

struct queue
{
    string data[MAX];
    int head;
    int tail;
};

queue antrian;

void create()
{
    antrian.head = antrian.tail = -1;
}

bool IsEmpty()
{
    if (antrian.tail == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool IsFull()
{
    if (antrian.tail == MAX - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Enqueue(string data)
{
    if (IsEmpty())
    {
        antrian.head = antrian.tail = 0;
        antrian.data[antrian.tail] = data;
    }
    else if (!IsFull())
    {
        antrian.tail++;
        antrian.data[antrian.tail] = data;
    }
    else
    {
        cout << "Queue is full" << endl;
    }
}

string Dequeue()
{
    string e = antrian.data[antrian.head];
    for (int i = antrian.head; i < antrian.tail; i++)
    {
        antrian.data[i] = antrian.data[i + 1];
    }
    antrian.tail--;
    return e;
}

int main()
{
    create();
    Enqueue("Data 1");
    Enqueue("Data 2");
    Enqueue("Data 3");

    cout << "Dequeued element: " << Dequeue() << endl;
    cout << "Dequeued element: " << Dequeue() << endl;

    return 0;
}
