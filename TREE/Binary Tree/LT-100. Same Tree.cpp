
//T.C = 0(N)
//S.C = 0(N)

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

      //  It avoids writing 3 separate if conditions
            // if(p == NULL || q == NULL)
            //  return p == q;

             
        // Case 1: Both nodes are NULL → trees match here
        if(!p && !q)
            return true;

        // Case 2: One is NULL and the other is not → mismatch
        if((!p && q) || (p && !q))
            return false;

        // Case 3: Both exist but values don't match
        if(p->val != q->val)
            return false;
         
        // Case 4: Check left & right subtrees
        return isSameTree(p->left,  q->left) &&
               isSameTree(p->right, q->right);
    }
};