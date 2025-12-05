
// T.C = 0(N)
//S.C  = 0(N)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> ans;

        // Edge case: empty tree
        if(!root)
            return ans;

        // Using reverse-preorder trick
        stack<TreeNode*> s;
        s.push(root);

        while(!s.empty()) {

            TreeNode* temp = s.top();
            s.pop();

            // Preorder: root → left → right
            // Postorder: left → right → root
            // So store root first, reverse at end
            ans.push_back(temp->val);

            // Push LEFT first? No →
            // Push LEFT last so that LEFT is processed before RIGHT after reverse.
            if(temp->left)
                s.push(temp->left);

            if(temp->right)
                s.push(temp->right);
        }

        // Reverse to convert ROOT-L-R → L-R-ROOT
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//----------------Using RECURSION-----------------------------------------
//T.C = 0(N)
//S.C = 0(N)

class Solution {
public:
    
    // Postorder = LEFT → RIGHT → ROOT
    void post(TreeNode* root, vector<int>& ans) {
        
        // Base case: NULL node
        if(!root)
            return;

        // 1. Traverse LEFT subtree
        post(root->left, ans);

        // 2. Traverse RIGHT subtree
        post(root->right, ans);

        // 3. Process ROOT node
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> ans;

        // Call recursive helper function
        post(root, ans);

        return ans;
    }
};
