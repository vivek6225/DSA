
//T.C = O(N)
//T.C = O(H)

class Solution {
public: 
   // Build BST from preorder traversal using range limits
   // 'index' points to current element in preorder array
   // 'lower' and 'upper' define valid range for current subtree
   TreeNode* BST(vector<int>& preorder, int &index, int lower, int upper){
    
        // Stop if all nodes are processed or value is out of range
        if(index == preorder.size() || 
           preorder[index] < lower || preorder[index] > upper)
            return NULL;

        // Create node from current preorder element
        TreeNode* root = new TreeNode(preorder[index++]);

        // Build left subtree with updated upper bound
        root->left  = BST(preorder, index, lower, root->val);

        // Build right subtree with updated lower bound
        root->right = BST(preorder, index, root->val, upper);
     
        return root;        // return constructed subtree
   }

   // Main function to construct BST from preorder traversal
   TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;      // start from first element
        return BST(preorder, index, INT_MIN, INT_MAX);
   }
};