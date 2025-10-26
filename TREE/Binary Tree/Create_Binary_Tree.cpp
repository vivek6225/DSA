
//-------------------- Method 1 -------------------------------------------------
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


//-------------------- Method 2 -------------------------------------------------

  #include <bits/stdc++.h>
using namespace std;

// Class representing a single node in the binary tree
class Node {
public:
    int data;        // stores value of the node
    Node *left;      // pointer to the left child
    Node *right;     // pointer to the right child

    // Constructor to initialize a node with a value
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Recursive function to create a binary tree
Node* BinaryTree() {
    int x;
    cin >> x;  // take user input for the current node

    // Base condition: if input is -1, return NULL (no node)
    if (x == -1)
        return NULL;

    // Create a new node
    Node *temp = new Node(x);

    // Recursively create the left subtree
    cout << "Enter the left child of " << x << " (-1 for no child): ";
    temp->left = BinaryTree();

    // Recursively create the right subtree
    cout << "Enter the right child of " << x << " (-1 for no child): ";
    temp->right = BinaryTree();

    // Return the created subtree
    return temp;
}

int main() {
    cout << "Enter the root node value (-1 for no node): ";
    Node *root = BinaryTree();  // create the binary tree

    cout << "\nBinary tree created successfully.\n";
    return 0;
}
  
