
//T.C = 0(N)
//S.C = 0(N)

class Solution {
  public:
    int height(Node* root) {
        if(root == NULL)
            return -1;  // empty tree height = -1 (so leaf becomes 0)
        
        return 1 + max(height(root->left), height(root->right));
    }
};
