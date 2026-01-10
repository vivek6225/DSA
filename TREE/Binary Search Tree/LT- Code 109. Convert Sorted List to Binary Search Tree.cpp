
//T.C = O(N)
//S.C = O(N)
class Solution {
public:

// This function builds a height-balanced BST from a sorted array
TreeNode* buildBST(vector<int>& Tree, int start, int end) {
    
    // Base case: no elements left
    if (start > end) return NULL;

    // Find middle element to keep tree balanced
    int mid = start + (end - start) / 2;

    // Create current root from middle value
    TreeNode* root = new TreeNode(Tree[mid]);

    // Recursively build left subtree from left half
    root->left  = buildBST(Tree, start, mid - 1);

    // Recursively build right subtree from right half
    root->right = buildBST(Tree, mid + 1, end);

    // Return constructed subtree root
    return root;
}

// Converts sorted linked list to balanced BST
TreeNode* sortedListToBST(ListNode* head) {
    
    vector<int> Tree;

    // Convert linked list into array
    while (head) {
        Tree.push_back(head->val);
        head = head->next;
    }

    // Build BST from sorted array
    return buildBST(Tree, 0, Tree.size() - 1);
}
};