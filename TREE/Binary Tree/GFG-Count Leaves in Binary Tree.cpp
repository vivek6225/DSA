
//T.C = 0(N)
//S.C = 0(N)

class Solution {
  public:

    int countLeaves(Node* root) {
    
        // If the root is NULL, no leaf exists here
        if(!root)
            return 0;

        // If BOTH left and right child are NULL → it's a leaf node
        if(!root->left && !root->right){
            return 1;   // Count this leaf
        }

        // Otherwise, recursively count leaves in left and right subtree
        return (countLeaves(root->left) + countLeaves(root->right));
    }
};

//--------------------------------OR-----------------------------------------------
class Solution {
  public:

    // Helper function to count leaf nodes
    void countLeaf(Node* root, int &count) {

        // If root is NULL, no node to process
        if(root == NULL)
            return;

        // If the node has NO left child AND NO right child → it's a leaf
        if(!root->left && !root->right){
            count++;        // Increase leaf count
            return;         // No need to go deeper
        }

        // Recursive call for left subtree (non-leaf node)
        countLeaf(root->left, count);

        // Recursive call for right subtree
        countLeaf(root->right, count);
    }

    // Main function to return total number of leaf nodes
    int countLeaves(Node* root) {
        int count = 0;          // Initialize leaf counter
        countLeaf(root, count); // Call helper function
        return count;           // Return final answer
    }
};
