
//T.C = 0(N)
//S.C = 0(N)
class Solution {
  public:
    vector<int> findSpiral(Node *root) {
        
        if(!root) return {};
        
        stack<Node*> s1; // Right to Left level
        stack<Node*> s2; // Left to Right level
        
        s1.push(root);
        
        vector<int> ans;
        
        while(!s1.empty() || !s2.empty()){
            
            // Process s1: Right to Left
            while(!s1.empty()){
                Node* temp = s1.top();
                s1.pop();
                
                ans.push_back(temp->data);
                
                // PUSH ORDER MATTERS
                if(temp->right)
                    s2.push(temp->right);
                if(temp->left)
                    s2.push(temp->left);
            }
            
            // Process s2: Left to Right
            while(!s2.empty()){
                Node* temp = s2.top();
                s2.pop();
                
                ans.push_back(temp->data);
                
                // PUSH ORDER MATTERS
                if(temp->left)
                    s1.push(temp->left);
                if(temp->right)
                    s1.push(temp->right);
            }
        }
        
        return ans;
    }
};
