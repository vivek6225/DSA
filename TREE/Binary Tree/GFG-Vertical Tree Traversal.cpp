
// Rule 1: Node with smaller vertical index (column) comes first.
// Rule 2: If column is same, node with smaller level (closer to root) comes first.

// T.C = 0(N)
//S.C = 0(N)


class Solution {
public:
    // This function finds the minimum (l) and maximum (r)
    // horizontal distance (column index) in the tree.
    // pos = current column index
    
    void find(Node* root, int pos, int &l, int &r) {
        // Base case: empty node
        if (!root) return;

        // Update leftmost and rightmost column indices
        l = min(l, pos);
        r = max(r, pos);

        // Move to left subtree (column - 1)
        find(root->left, pos - 1, l, r);

        // Move to right subtree (column + 1)
        find(root->right, pos + 1, l, r);
    }

    vector<vector<int>> verticalOrder(Node *root) {

        // l = leftmost column index
        // r = rightmost column index
        int l = 0, r = 0;

        // First DFS to determine column range
        find(root, 0, l, r);

        // Separate storage for negative (left side) columns
        // and positive (right side) columns
        vector<vector<int>> negative(abs(l) + 1);
        vector<vector<int>> positive(r + 1);

        // BFS traversal queues
        queue<Node*> q;   // stores tree nodes
        queue<int> idx;   // stores corresponding column indices

        // Start BFS from root at column 0
        q.push(root);
        idx.push(0);

        // Level order traversal
        while (!q.empty()) {

            Node* temp = q.front();
            q.pop();

            int pos = idx.front();
            idx.pop();

            // Store node value in appropriate column
            if (pos >= 0)
                positive[pos].push_back(temp->data);
            else
                negative[abs(pos)].push_back(temp->data);

            // Push left child with column index -1
            if (temp->left) {
                q.push(temp->left);
                idx.push(pos - 1);
            }

            // Push right child with column index +1
            if (temp->right) {
                q.push(temp->right);
                idx.push(pos + 1);
            }
        }

        // Final answer: combine columns from leftmost to rightmost
        vector<vector<int>> ans;

        // Add negative columns (from leftmost to center)
        for (int i = negative.size() - 1; i > 0; i--)
            ans.push_back(negative[i]);

        // Add positive columns (from center to rightmost)
        for (int i = 0; i < positive.size(); i++)
            ans.push_back(positive[i]);

        return ans;
    }
};
