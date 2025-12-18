// T.C = O(N * M)  
// S.C = O(H) 

class Solution {
public:

    // This function checks whether two trees are exactly identical
    // (same structure + same node values)
    bool isIdentical(TreeNode* p, TreeNode* q) {

        // If either node is NULL:
        // return true only if both are NULL
        if(p == NULL || q == NULL){
            return p == q;
        }

        // Check:
        // 1. current node values are same
        // 2. left subtrees are identical
        // 3. right subtrees are identical
        return p->val == q->val &&
               isIdentical(p->left, q->left) &&
               isIdentical(p->right, q->right);
    }

    // This function checks whether subRoot exists as a subtree of root
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        // If either tree is NULL:
        // they are subtrees only if both are NULL
        if(root == NULL || subRoot == NULL){
            return root == subRoot;
        }

        // If values match, check if both trees are identical from this node
        if(root->val == subRoot->val && isIdentical(root, subRoot)){
            return true;
        }

        // Otherwise, search subRoot in left OR right subtree of root
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};