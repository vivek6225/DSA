
//T.C = 0(N)
//S.C = 0(N)

class Solution {
  public:
    int height(Node* root, bool &valid) {

        // Base case: empty subtree has height 0
        if(!root)
            return 0;

        // Recursively find left & right subtree heights
        int l = height(root->left, valid);
        int r = height(root->right, valid);

        // If difference > 1 → tree becomes unbalanced
        if(abs(l - r) > 1)
            valid = 0;

        // Height of current node
        return 1 + max(l, r);
    }

    bool isBalanced(Node* root) {
        bool valid = 1;        // Assume tree is balanced initially
        height(root, valid);   // Recursively compute height and check balance
        return valid;
    }
};
