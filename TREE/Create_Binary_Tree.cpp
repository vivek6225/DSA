#include <bits/stdc++.h>
using namespace std;

// Node class represents each node in the binary tree
class Node {
public:
    int data;          // stores node value
    Node *left, *right; // pointers to left and right child

    // Constructor to initialize a new node
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

int main() {
    int x;
    cout << "Enter the root element: ";
    cin >> x;

    // Create the root node
    Node *root = new Node(x);

    // Queue is used for level order tree construction
    queue<Node*> q;
    q.push(root);

    // Build binary tree level-wise
    while (!q.empty()) {
        Node *temp = q.front();  // get front node
        q.pop();                 // remove it from the queue

        int first, second;

        // Input left child
        cout << "Enter the left child of " << temp->data << " (-1 for no child): ";
        cin >> first;

        // If left child exists, create new node and link it
        if (first != -1) {
            temp->left = new Node(first);
            q.push(temp->left);  // push new node to queue for further processing
        }

        // Input right child
        cout << "Enter the right child of " << temp->data << " (-1 for no child): ";
        cin >> second;

        // If right child exists, create new node and link it
        if (second != -1) {
            temp->right = new Node(second);
            q.push(temp->right); // push new node to queue
        }
    }

    cout << "\nBinary tree created successfully.\n";
    return 0;
}
