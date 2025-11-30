
//T.C = 0(N)
//S.c = 0(N)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;
        
        // Edge case: empty tree
        if(!root)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        // Level Order Traversal (BFS)
        while(!q.empty()){

            // ---- RIGHT VIEW LOGIC ----
            // Har level ka LAST node right view hota hai
            ans.push_back(q.front()->val);  

            int n = q.size();   // current level ke nodes kitne hain

            // current level ke saare nodes process karo
            while(n--){
                TreeNode* temp = q.front();
                q.pop();

                // IMPORTANT:
                // Right view ke liye pehle RIGHT daalo, fir LEFT
                if(temp->right)
                    q.push(temp->right);

                if(temp->left)
                    q.push(temp->left);
            }
        }

        return ans;
    }
};
//----------using RECURSION-----------------------------------------------------
class Solution {
public:

    void rightview(TreeNode* root, int level, vector<int>& ans) {

        // Base condition: agar node NULL ho gaya, return
        if(!root)
            return;

        /* 
           IMPORTANT CONCEPT:
           ------------------------------------------
           - Right View = har level ka pehla RIGHT se dikhta node
           - DFS call order hum RIGHT -> LEFT rakhte hain
           - Jab hum kisi level par PEHLI baar aate hain
             (i.e., level == ans.size())
             tab wahi RIGHT VIEW ka node hota hai.
        */
        if(level == ans.size())
            ans.push_back(root->val);

        // Right view ke liye:
        // Pehle RIGHT subtree, fir LEFT subtree
        rightview(root->right, level + 1, ans);
        rightview(root->left,  level + 1, ans);
    }

    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;

        // Edge case: empty tree ka right view empty hota hai
        if(!root)
            return ans;

        // DFS start from root at level 0
        rightview(root, 0, ans);

        return ans;
    }
};
