
//T.C = 0(N)
//S.C = 0(N)

class Solution {
  public:
    int countNonLeafNodes(Node* root) {
        
        // If tree is empty → no non-leaf nodes
        if(!root)
            return 0;
        
        // If this node is a leaf (no left and no right child)
        // then it is NOT counted as a non-leaf node
        if(!root->left && !root->right)
            return 0;
        
        // Otherwise, this node is a non-leaf node.
        // Count this node (1) + count non-leaf nodes in left subtree
        // + count non-leaf nodes in right subtree.
        return 1 + countNonLeafNodes(root->left) 
                 + countNonLeafNodes(root->right);
    }
};
