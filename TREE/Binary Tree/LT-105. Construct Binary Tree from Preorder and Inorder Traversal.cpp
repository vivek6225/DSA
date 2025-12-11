
// T.C = 0(N²)
//S.C = 0(N)

class Solution {
public:

    // Searches for a value in inorder array between start and end
    // and returns its index
    int search(vector<int>& inorder, int start, int end, int val) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == val) {
                return i;          // return index of root in inorder
            }
        }
        return -1;                 // value not found (invalid case)
    }

    // Recursive helper function to build tree
    // preorder  → gives root nodes in order
    // inorder   → helps divide left & right subtree
    // preIdx    → keeps track of current root in preorder
    // left,right→ current range in inorder array
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int &preIdx, int left, int right) {
        // Base condition: no elements to construct subtree
        if (left > right)
            return NULL;

        // Create root node using current preorder index
        TreeNode* root = new TreeNode(preorder[preIdx]);

        // Find root position in inorder to split left & right subtree
        int inIdx = search(inorder, left, right, preorder[preIdx]);

        // Move to next root in preorder
        preIdx++;

        // Build left subtree using left part of inorder
        root->left = helper(preorder, inorder, preIdx, left, inIdx - 1);

        // Build right subtree using right part of inorder
        root->right = helper(preorder, inorder, preIdx, inIdx + 1, right);

        // Return constructed root
        return root;
    }

    // Main function that starts tree construction
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preidx = 0;  // Initial index for preorder traversal
        return helper(preorder, inorder, preidx, 0, inorder.size() - 1);
    }
};
