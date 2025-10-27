
//T.C = 0(N)
//S.c = 0(N)

class Solution {
public:
    // Helper function for preorder traversal (Node -> Left -> Right)
    void pre(Node *root, vector<int>& ans) {

        // Base condition: if current node is NULL, return
        if (root == NULL)
            return;

        // Step 1: Visit the current node (Node)
        ans.push_back(root->data);

        // Step 2: Traverse the left subtree (Left)
        pre(root->left, ans);

        // Step 3: Traverse the right subtree (Right)
        pre(root->right, ans);
    }

    // Main function to return preorder traversal of the binary tree
    vector<int> preOrder(Node* root) {
        vector<int> ans;    // Vector to store the preorder traversal
        pre(root, ans);     // Call helper function
        return ans;         // Return the result
    }
};
