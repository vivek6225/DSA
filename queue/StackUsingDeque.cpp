#include <bits/stdc++.h>
using namespace std;

class Deque {
    int front, rear, size;
    int *arr;

public:
    Deque(int n) {
        size = n;
        rear = front = -1;
        arr = new int[n];
    }

    // ~Deque() {
    //     delete[] arr;
    // }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    void push_front(int x) {
        if (isFull()) {
            cout << "Overflow\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            front = (front - 1 + size) % size;
        }
        arr[front] = x;
        cout << "Pushed " << x << " in front\n";
    }

    void push_back(int x) {
        if (isFull()) {
            cout << "Overflow\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        arr[rear] = x;
        cout << "Pushed " << x << " in back\n";
    }

    void pop_front() {
        if (isEmpty()) {
            cout << "Underflow\n";
            return;
        }
        cout << "Popped " << arr[front] << " from front\n";
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    void pop_back() {
        if (isEmpty()) {
            cout << "Underflow\n";
            return;
        }
        cout << "Popped " << arr[rear] << " from back\n";
        if (front == rear) {
            front = rear = -1;
        } else {
            rear = (rear - 1 + size) % size;
        }
    }

    int start() {
        return isEmpty() ? -1 : arr[front];
    }

    int end() {
        return isEmpty() ? -1 : arr[rear];
    }
};

int main() {
    Deque d(5);
    d.push_back(1);
    d.push_back(4);
    d.push_front(0);
    cout << "Front: " << d.start() << endl;
    cout << "Rear: " << d.end() << endl;
    d.pop_back();
    d.pop_front();
    cout << "Front after pop: " << d.start() << endl;
}
