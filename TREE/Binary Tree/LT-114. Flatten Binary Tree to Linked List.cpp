
// T.C = 0(N)
//S.C = 0(1)

class Solution {
public:
    void flatten(TreeNode* root) {

        // Iterate through the tree using current node
        while (root) {

            // If there is no left child,
            // simply move to the right
            if (!root->left) {
                root = root->right;
            }
            else {
                // Find the rightmost node of left subtree
                // (inorder predecessor)
                TreeNode* curr = root->left;
                while (curr->right)
                    curr = curr->right;

                // Attach the original right subtree
                // to the rightmost node of left subtree
                curr->right = root->right;

                // Move left subtree to the right
                root->right = root->left;

                // Set left to NULL as per linked list requirement
                root->left = NULL;

                // Move to next node (which is now right child)
                root = root->right;
            }
        }
    }
};
