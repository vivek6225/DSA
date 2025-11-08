
// T.C =0(N)
// S.C =0(N)

class Solution {
public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> ans; // This will store the final result in 2D format (level-wise)

       
        if(root == NULL) 
            return ans; 
        
        queue<Node*> q;              
        q.push(root);   

        while(!q.empty()){
            int size = q.size();     // Number of nodes present at current level
            vector<int> level;       // Temporary list to store current level nodes

            // Process all nodes of this level
            while(size--){
                Node *temp = q.front();  // Get front node from queue
                q.pop();                 // Remove it from queue

                level.push_back(temp->data); // Store node data in current level list

                if(temp->left)             // If left child exists,
                    q.push(temp->left);    // push into queue for next level

                if(temp->right)            // If right child exists,
                    q.push(temp->right);   // push into queue for next level
            }

            ans.push_back(level);     // Add the completed level into answer vector
        }
        
        return ans;                   // Return all levels of the tree
    }
};