
//T.C = 0(N)
//S.C = 0(N)

class Solution {
  public:
    int countNonLeafNodes(Node* root) {
        
        if(!root)
        return 0;
        
        if(!root->left && !root->right)
        return 0;
        return(1 +countNonLeafNodes(root->left)+countNonLeafNodes(root->right));
        
    }
};