
// t.c = 0(N)
//S.C = 0(N)

class Solution {
public:
    int getSize(Node* root) {
        
        // If the node is NULL, it contributes 0 to the size
        if(!root)
            return 0;
        
    // Return 1 (for current node) + size of left subtree + size of right subtree
        return (1 + getSize(root->left) + getSize(root->right));
    }
};
//-----------------------------OR---------------------------------------------------
class Solution {
public:

    void Total(Node *root, int &count) {

        if(root == NULL)        
            return;

        count++;            

        Total(root->left, count);   // Recur for left subtree
        Total(root->right, count);  // Recur for right subtree
    }
        
    int getSize(Node* root) {

        int count = 0;          // Initialize count of nodes

        Total(root, count);     // Call helper function to count nodes

        return count;           // Return total number of nodes
    }
};
