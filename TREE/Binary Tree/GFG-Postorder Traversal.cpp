
//T.C = 0(N)
//S.C = 0(N)

class Solution {
public:
    // Helper function for Postorder: Left -> Right -> Node
    void post(Node *root, vector<int>& ans) {
        if (root == NULL)
            return;

        // Left subtree
        post(root->left, ans);

        // Right subtree
        post(root->right, ans);

        // Node
        ans.push_back(root->data);
    }

    vector<int> postOrder(Node* root) {
        vector<int> ans;
        post(root, ans);  // call helper function
        return ans;
    }
};
