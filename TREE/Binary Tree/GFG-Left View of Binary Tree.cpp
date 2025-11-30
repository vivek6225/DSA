
//T.C = 0(N)
//S.C = 0(N)

class Solution {
  public:
    vector<int> leftView(Node *root) {
        
        vector<int> ans;

        // Edge case: agar tree empty ho to left view empty milega
        if(!root) 
            return ans;

        queue<Node*> q;
        q.push(root);

        // Level order traversal (BFS)
        while(!q.empty()){

            // ---- LEFT VIEW LOGIC ----
            // Har level ka PEHLA node hi left view hota hai
            ans.push_back(q.front()->data);

            int n = q.size();  // current level ke total nodes
            
            // Current level ke saare nodes process karo
            while(n--){
                Node *temp = q.front();
                q.pop();

                // Left child ko queue me daalo (pehle left aayega)
                if(temp->left)
                    q.push(temp->left);

                // Right child ko queue me daalo
                if(temp->right)
                    q.push(temp->right);
            }
        }

        return ans;
    }
};
//-------------------using RECURSION---------------------------------------------
class Solution {
  public:

   
    void leftview(Node* root, int level, vector<int>& ans) {

        // Base case: agar node hi nahi hai
        if(!root)
            return;

        // IMPORTANT:
        // Jab kisi level par hum pehli baar aa rahe hote hain,
        // ans.size() == level hota hai.
        // Pehla node hi LEFT VIEW hota hai.
        if(level == ans.size())
            ans.push_back(root->data);

        // LEFT VIEW ke liye: pehle LEFT subtree, fir RIGHT
        leftview(root->left,  level + 1, ans);
        leftview(root->right, level + 1, ans);
    }

    vector<int> leftView(Node *root) {

        vector<int> ans;

        // Edge case: empty tree ka left view empty hota hai
        if(!root)
            return ans;

        // Starting from root at level 0
        leftview(root, 0, ans);

        return ans;
    }
};

