class Solution {
public:

    // ---------------- LEFT BOUNDARY ----------------
    // Traverses the left boundary from top to bottom.
    // Leaf nodes are excluded to avoid duplication.
    void leftSub(Node *root, vector<int>& ans) {

        // Stop if node is NULL or it is a leaf node
        if (!root || (!root->left && !root->right))
            return;

        // Current node is part of left boundary
        ans.push_back(root->data);

        // Prefer left child; if not present, move to right child
        if (root->left)
            leftSub(root->left, ans);
        else
            leftSub(root->right, ans);
    }

    // ---------------- LEAF NODES ----------------
    // Collects all leaf nodes in left-to-right order.
    void leaf(Node *root, vector<int>& ans) {

        // Base case
        if (!root)
            return;

        // If node has no children, it is a leaf
        if (!root->left && !root->right) {
            ans.push_back(root->data);
            return;
        }

        // Recursively check left and right subtrees
        leaf(root->left, ans);
        leaf(root->right, ans);
    }

    // ---------------- RIGHT BOUNDARY ----------------
    // Traverses the right boundary from bottom to top.
    // Leaf nodes are excluded.
    void rightSub(Node *root, vector<int>& ans) {

        // Stop if node is NULL or it is a leaf node
        if (!root || (!root->left && !root->right))
            return;

        // Prefer right child; if not present, move to left child
        if (root->right)
            rightSub(root->right, ans);
        else
            rightSub(root->left, ans);

        // Add node after recursion to maintain bottom-up order
        ans.push_back(root->data);
    }

    // ---------------- MAIN FUNCTION ----------------
    vector<int> boundaryTraversal(Node *root) {

        vector<int> ans;

        // Edge case: empty tree
        if (!root)
            return ans;

        // Step 1: Add root node (added only once)
        ans.push_back(root->data);

        // Step 2: Add left boundary (excluding leaf nodes)
        leftSub(root->left, ans);

        // Step 3: Add all leaf nodes (excluding root)
        leaf(root->left, ans);
        leaf(root->right, ans);

        // Step 4: Add right boundary (excluding leaf nodes)
        rightSub(root->right, ans);

        return ans;
    }
};
