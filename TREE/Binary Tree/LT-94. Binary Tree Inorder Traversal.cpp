
// ---------------------  Using RECURSION   ----------------------------------------
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

//---------------------------  using Morris  ------------------------------------

// T.C = 0(N)
//S.C = 0(1)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans;

        // Traverse until root becomes NULL
        while (root) {

            // Case 1: No left child
            // Visit node and go right
            if (!root->left) {
                ans.push_back(root->val);
                root = root->right;
            }
            else {
                // Find inorder predecessor
                TreeNode* curr = root->left;

                // Move to rightmost node of left subtree
                // or stop if thread already exists
                while (curr->right && curr->right != root)
                    curr = curr->right;

                // Case 2: Create temporary thread
                if (curr->right == NULL) {
                    curr->right = root;     // thread
                    root = root->left;      // move left
                }
                // Case 3: Thread already exists → remove it
                else {
                    curr->right = NULL;     // remove thread
                    ans.push_back(root->val); // visit root
                    root = root->right;     // move right
                }
            }
        }

        return ans;
    }
};
