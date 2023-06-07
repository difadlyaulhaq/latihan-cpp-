#include <iostream>

using namespace std;

const int MAX_SIZE = 5;

class Queue {
private:
    int data[MAX_SIZE];
    int head;
    int tail;

public:
    Queue() {
        head = -1;
        tail = -1;
    }

    bool isEmpty() {
        return (head == -1 && tail == -1);
    }

    bool isFull() {
        return (tail + 1) % MAX_SIZE == head;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Unable to enqueue." << endl;
            return;
        }
        else if (isEmpty()) {
            head = 0;
            tail= 0;
        }
        else {
            tail = (tail + 1) % MAX_SIZE;
        }

        data[tail] = value;
        cout << "Enqueued " << value << " to the queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Unable to dequeue." << endl;
            return;
        }
        else if (head == tail) {
            head = -1;
            tail = -1;
        }
        else {
            head = (tail + 1) % MAX_SIZE;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. No element to peek." << endl;
            return -1;
        }

        return data[head];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue: ";
        int i = head;
        while (i != tail) {
            cout << data[i] << " ";
            i = (i + 1) % MAX_SIZE;
        }
        cout << data[tail] << endl;
    }
};

int main() {
    Queue myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);
    myQueue.enqueue(40);
    myQueue.enqueue(50);
    myQueue.enqueue(60); // Queue is full. Unable to enqueue.

    myQueue.display(); // Queue: 10 20 30 40 50

    myQueue.dequeue();
    myQueue.dequeue();

    myQueue.display(); // Queue: 30 40 50

    cout << "Front element: " << myQueue.peek() << endl; // Front element: 30

    return 0;
}
