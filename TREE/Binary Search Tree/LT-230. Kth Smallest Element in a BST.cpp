
//------------------------Optimal Approach------------------------------------------
// T.C = O(H + k) best, O(N) worst
  // S.C = O(H)
  
  class Solution {
public:

    // Inorder traversal (Left → Root → Right)
    // 'k' keeps track of how many smallest nodes are still left to skip
    // When k becomes 0, current node is the k-th smallest
    void Ksmallest(TreeNode* root, int &ans, int &k){

        if(!root)
            return;                 // base case
        
        Ksmallest(root->left, ans, k);   // visit left subtree (smaller values first)

        k--;                        // one node processed

        if(k == 0)
            ans = root->val;        // store k-th smallest value

        // if k-th smallest already found, stop further traversal
        if(k <= 0)
            return;

        Ksmallest(root->right, ans, k);  // visit right subtree
    }

    int kthSmallest(TreeNode* root, int k) {
        
        int ans;                   // stores final answer
        Ksmallest(root, ans, k);   // start inorder traversal
        return ans;                // return k-th smallest value
    }
};



//------------------------Better Approach---------------------------------------
//T.C = 0(N)
//S.C = 0(N)
class Solution {
public:
    
   // Inorder traversal of BST gives nodes in sorted (ascending) order
   void Inorder(TreeNode* root, vector<int>& ans){
        if(!root)
            return;                     // base case

        Inorder(root->left, ans);       // visit left subtree
        ans.push_back(root->val);       // store current node value
        Inorder(root->right, ans);      // visit right subtree
    }

    int kthSmallest(TreeNode* root, int k) {

        vector<int> ans;               // stores inorder traversal result
        Inorder(root, ans);            // fill vector in sorted order

        return ans[k-1];               // k-th smallest element (0-based index)
    }
};
