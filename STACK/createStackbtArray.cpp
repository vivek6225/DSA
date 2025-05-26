#include <bits/stdc++.h>
using namespace std;

class MyStack {
    int top;
    int* arr;
    int size;

public:
    MyStack(int size) {
        arr = new int[size];
        top = -1;
        this->size = size;
    }

    void push(int data) {
        if (top == size - 1) {
            cout << "Stack overflow\n";
            return;
        }
        arr[++top] = data;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack underflow\n";
            return;
        }
        top--;
    }

    int peak() {
        if (top == -1) {
            cout << "Stack underflow\n";
            return -1;
        }
        return arr[top];
    }

    bool empty() {
        return top == -1;
    }

    ~MyStack() {
        delete[] arr;
    }
};

int main() {
    MyStack s(4);
    s.push(16);
    s.push(10);
    cout << s.peak() << endl; // Should output 10
    return 0;
}
