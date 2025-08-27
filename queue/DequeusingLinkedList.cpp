//t.c =0(1)
//s.c =0(n)

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next, *prev;
    Node(int value) {
        data = value;
        next = prev = NULL;
    }
};

class Dequeue {
    Node *front, *rear;

public:
    Dequeue() {
        front = rear = NULL;
    }

    // Check if empty
    bool isEmpty() {
        return front == NULL;
    }

    // push front
    void push_front(int x) {
        if (isEmpty()) {
            front = rear = new Node(x);
        } else {
            Node *temp = new Node(x);
            temp->next = front;
            front->prev = temp;
            front = temp;
        }
        cout << "pushed " << x << " in front of Dequeue\n";
    }

    // push back
    void push_back(int x) {
        if (isEmpty()) {
            front = rear = new Node(x);
        } else {
            Node *temp = new Node(x);
            rear->next = temp; 
            temp->prev = rear;
            rear = temp;
        }
        cout << "pushed " << x << " in back of Dequeue\n";
    }

    // pop front
    void pop_front() {
        if (isEmpty()) {
            cout << "Queue underflow\n";
            return;
        }
        Node *temp = front;
        cout << "popped " << temp->data << " from front\n";
        front = front->next;
        delete temp;
        if (front)
            front->prev = NULL;
        else
            rear = NULL;
    }

    // pop back
    void pop_back() {
        if (isEmpty()) {
            cout << "Queue underflow\n";
            return;
        }
        Node *temp = rear;
        cout << "popped " << temp->data << " from back\n";
        rear = rear->prev;
        delete temp;
        if (rear)
            rear->next = NULL;
        else
            front = NULL;
    }

    // start
    int start() {
        if (isEmpty())
            return -1;
        return front->data;
    }

    // end
    int end() {
        if (isEmpty())
            return -1;
        return rear->data;
    }
};

int main() {
    Dequeue d;
    d.push_back(3);
    d.push_front(3);
    d.pop_back();
    d.pop_back();
    d.pop_back();
    cout << d.start() << endl;
}
