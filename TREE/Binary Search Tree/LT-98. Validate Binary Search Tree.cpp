
// T.C = 0(N)
//S.C = 0(H)

class Solution {
public:

    // This function checks BST using inorder traversal
    // 'prev' stores the value of the previously visited node
    bool BST(TreeNode* root, int &prev){
      
        if(!root)
            return 1;              // empty tree is valid BST

        // check left subtree
        bool l = BST(root->left, prev);
        if(l == 0)
            return 0;              // left subtree is invalid

        // current node must be greater than previous node
        if(root->val <= prev)
            return 0;              // BST property violated

        // update previous node value
        prev = root->val;

        // check right subtree
        return BST(root->right, prev);
    }

    bool isValidBST(TreeNode* root) {

        int prev = INT_MIN;        // initialize previous with minimum value
        return BST(root, prev);   // start validation
    }
};

//----------------------------Better Approach--------------------------------
// T.C = 0(N)
//S.C = 0(N)

class Solution {
public:

    // Inorder traversal: Left → Root → Right
    void inorder(TreeNode* root, vector<int>& ans) {
        if(!root) return;   // base case

        inorder(root->left, ans);      // visit left subtree
        ans.push_back(root->val);      // store current node value
        inorder(root->right, ans);     // visit right subtree
    }

    bool isValidBST(TreeNode* root) {

        vector<int> ans;              // stores inorder traversal result
        inorder(root, ans);           // fill vector

        // Check if array is strictly increasing
        for(int i = 1; i < ans.size(); i++) {
            if(ans[i] <= ans[i-1])    // BST property violated
                return false;
        }

        return true;                  // valid BST
    }
};