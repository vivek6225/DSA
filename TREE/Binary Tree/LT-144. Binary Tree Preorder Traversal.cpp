
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> ans;

        // Edge case: empty tree
        if(!root)
            return ans;

        stack<TreeNode*> s;
        s.push(root);

        while(!s.empty()) {
            TreeNode* temp = s.top();
            s.pop();

            // ROOT → add to answer
            ans.push_back(temp->val);

           
            // Push RIGHT first so LEFT is processed before (LIFO stack)
            if(temp->right)
                s.push(temp->right);

            if(temp->left)
                s.push(temp->left);
        }

        return ans;
    }
};


//---------------------------using RECURSION------------------------------
//T.C = 0(N)
//S.c = 0(N)

class Solution {
public:
void pre (TreeNode*root,vector<int>&ans){
    if(!root)
    return ;
    //step 1: visit current node
    ans.push_back(root->val);
     // step 2: traverse left sub tree
    pre(root->left,ans);
    // step 3: traverse right sub tree
    pre(root->right,ans);
}
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        pre(root,ans);
        return ans;
        
    }
};