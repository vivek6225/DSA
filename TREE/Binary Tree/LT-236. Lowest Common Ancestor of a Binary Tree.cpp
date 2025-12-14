
//T.C = 0(N)
//S.C = 0(N)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // Base case: if tree is empty
        if(root == NULL){
            return NULL;
        }

        // If current node is either p or q, this node could be a potential LCA
        // Because we found one of the targets
        if(root->val == p->val || root->val == q->val){
            return root;
        }

        // Recursively search in left subtree
        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);

        // Recursively search in right subtree
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

        // If both left and right returned non-null:
        // It means p is found in one subtree, q in the other.
        // So current node is the LCA.
        if(leftLCA && rightLCA){
            return root;
        }
        // If only left returns non-null, LCA is in left subtree
        else if(leftLCA != NULL){
            return leftLCA;
        }
        // If only right returns non-null, LCA is in right subtree
        else{
            return rightLCA;
        }
    }
};
