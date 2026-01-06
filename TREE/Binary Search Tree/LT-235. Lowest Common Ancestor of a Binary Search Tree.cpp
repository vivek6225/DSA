
// T.C = O(N)
// S.C = O(N)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(!root)
            return NULL;   // base case

        // If both p and q are smaller, move to left subtree
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        
        // If both p and q are larger, move to right subtree
        else if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);

        // Otherwise, current node is the LCA
        else
            return root;
    }
};