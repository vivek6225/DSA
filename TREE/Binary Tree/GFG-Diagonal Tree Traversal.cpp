
//T.C = 0(N)
//S.C =0(N)

class Solution {
public:

    // This function finds the maximum diagonal index needed
    // pos = current diagonal number
    void find(Node *root, int pos, int &l) {
        // Base case
        if (!root) return;

        // Update maximum diagonal number
        l = max(l, pos);

        // Left child goes to next diagonal
        find(root->left, pos + 1, l);

        // Right child stays on same diagonal
        find(root->right, pos, l);
    }

    // This function fills diagonal-wise nodes
    void findDig(Node *root, int pos, vector<vector<int>> &ans) {
        if (!root)
            return;

        // Add current node to its diagonal
        ans[pos].push_back(root->data);

        // Left child → next diagonal
        findDig(root->left, pos + 1, ans);

        // Right child → same diagonal
        findDig(root->right, pos, ans);
    }

    vector<int> diagonal(Node *root) {

        int l = 0;   // maximum diagonal index
        find(root, 0, l);

        // Create storage for each diagonal
        vector<vector<int>> ans(l + 1);

        // Fill diagonals
        findDig(root, 0, ans);

        // Flatten result into single vector
        vector<int> temp;
        for (int i = 0; i < ans.size(); i++)
            for (int j = 0; j < ans[i].size(); j++)
                temp.push_back(ans[i][j]);

        return temp;
    }
};
