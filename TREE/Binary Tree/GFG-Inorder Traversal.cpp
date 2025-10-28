
//T.C = 0(N)
//S.c = 0(N)

class Solution {
public:
    // Helper function for inorder traversal (Left -> Node -> Right)
    void inOrd(Node* root, vector<int>& ans) {
        // Base condition
        if (root == NULL)
            return;

        // Step 1: Traverse left subtree
        inOrd(root->left, ans);

        // Step 2: Visit current node
        ans.push_back(root->data);

        // Step 3: Traverse right subtree
        inOrd(root->right, ans);
    }

    // Main function to return inorder traversal
    vector<int> inOrder(Node* root) {
        vector<int> ans;        // Vector to store traversal result
        inOrd(root, ans);       // Call helper function
        return ans;             // Return the final inorder list
    }
};
