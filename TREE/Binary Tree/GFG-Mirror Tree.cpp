
//T.C = 0(N)
//S.C = 0(N)

class Solution {
  public:
    void mirror(Node* root) {

        // Base case: if tree/subtree is empty → nothing to mirror
        if(!root)
            return;

        // Swap left and right children
        Node* temp = root->right;
        root->right = root->left;
        root->left = temp;

        // Recursively mirror the left subtree
        mirror(root->left);

        // Recursively mirror the right subtree
        mirror(root->right);
    }
};
