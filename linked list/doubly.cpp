#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {  // constructor
        data = val;
        next = prev = NULL;
    }
};

int main() {
    Node* head = NULL;

    if (head == NULL)
        head = new Node(5);
    else {
        Node* temp = new Node(9);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }

    // Add another node just to show multiple nodes
    Node* temp2 = new Node(9);
    temp2->next = head;
    head->prev = temp2;
    head = temp2;

    Node* trav = head;
    while (trav) {
        cout << trav->data << "-> ";
        trav = trav->next;
    }

    return 0;
}
