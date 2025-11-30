

class Solution {
  public:

    // DFS se horizontal range (leftmost = l, rightmost = r) nikalna
    void find(Node* root, int pos, int &l, int &r) {
        
        if(!root) 
            return;

        // pos = horizontal distance
        // Minimum HD leftmost node deta hai
        // Maximum HD rightmost node deta hai
        l = min(l, pos);
        r = max(r, pos);

        // LEFT child ka HD = pos - 1
        find(root->left, pos - 1, l, r);

        // RIGHT child ka HD = pos + 1
        find(root->right, pos + 1, l, r);
    }

    vector<int> topView(Node *root) {

        // horizontal limits
        int l = 0, r = 0;

        // Step 1: find horizontal distance range
        find(root, 0, l, r);

        int total = r - l + 1;

        vector<int> ans(total);        // final top view
        vector<bool> filled(total, 0); // mark which hd is filled

        queue<Node*> q;
        queue<int> index; // stores horizontal distance (shifted)

        // shift hd by 'l' so that min hd becomes 0 index
        q.push(root);
        index.push(0 - l);

        // BFS → Top View = first node of each horizontal distance
        while(!q.empty()) {

            Node* temp = q.front();
            q.pop();

            int pos = index.front();
            index.pop();

            // If this horizontal distance is not filled yet,
            // then this node is FIRST seen → TOP VIEW
            if(!filled[pos]) {
                filled[pos] = 1;
                ans[pos] = temp->data;
            }

            // LEFT child: hd = pos - 1
            if(temp->left) {
                q.push(temp->left);
                index.push(pos - 1);
            }

            // RIGHT child: hd = pos + 1
            if(temp->right) {
                q.push(temp->right);   // <-- semicolon fixed
                index.push(pos + 1);
            }
        }

        return ans;
    }
};
