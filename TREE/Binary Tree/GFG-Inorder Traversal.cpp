


// ---------------------Using RECURSION-----------------------------------
//T.C = 0(N)
//S.c = 0(N)

class Solution {
public:

    // Helper function for inorder traversal
    // Inorder = Left → Node → Right
    void inord(TreeNode* root, vector<int>& ans) {

        // Base case: NULL node
        if(!root)
            return;

        // 1. Traverse LEFT subtree
        inord(root->left, ans);

        // 2. Visit ROOT node
        ans.push_back(root->val);

        // 3. Traverse RIGHT subtree
        inord(root->right, ans);
    }

    // Main function to get inorder traversal
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        // call recursive helper
        inord(root, ans);

        return ans;
    }
};


