
// T.C = 0(N)
//S.C = 0(H)

class Solution {
public:
   
    // Inorder traversal to find minimum difference between adjacent nodes
    // 'prev' stores previously visited node value
    // 'ans' stores minimum difference found so far
    void minDiff(TreeNode* root, int& prev, int& ans){
        
        if(!root)
            return;                 // base case

        minDiff(root->left, prev, ans);   // visit left subtree

        // calculate difference with previous node
        if(prev != INT_MIN)
            ans = min(ans, root->val - prev);

        prev = root->val;           // update previous value

        minDiff(root->right, prev, ans);  // visit right subtree
    }

    int minDiffInBST(TreeNode* root) {
        int prev = INT_MIN;         // previous node value
        int ans = INT_MAX;          // minimum difference answer

        minDiff(root, prev, ans);   // start inorder traversal
        return ans;                 // return final minimum difference
    }
};