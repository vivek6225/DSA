
// T.C = O(n + m)
// S.C = O(n + m)
class Solution {
public:

    // Inorder traversal of BST
    // This stores the BST elements in sorted order into 'ans'
    void Inorder(TreeNode* root, vector<int>& ans) {
        if(!root) return;

        Inorder(root->left, ans);        // visit left subtree
        ans.push_back(root->val);        // store current node
        Inorder(root->right, ans);       // visit right subtree
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {

        vector<int> ans1;   // stores sorted elements of BST1
        vector<int> ans2;   // stores sorted elements of BST2

        Inorder(root1, ans1);   // inorder of first BST
        Inorder(root2, ans2);   // inorder of second BST

        vector<int> ans;   // final merged sorted array

        int i = 0, j = 0;  // pointers for ans1 and ans2

        // merge both sorted arrays
        while(i < ans1.size() && j < ans2.size()) {

            if(ans1[i] < ans2[j]) {
                ans.push_back(ans1[i]);  // push smaller element
                i++;                     // move pointer of ans1
            }
            else {
                ans.push_back(ans2[j]);  // push smaller element
                j++;                     // move pointer of ans2
            }
        }

        // push remaining elements of ans1 (if any)
        while(i < ans1.size()) {
            ans.push_back(ans1[i]);
            i++;
        }

        // push remaining elements of ans2 (if any)
        while(j < ans2.size()) {
            ans.push_back(ans2[j]);
            j++;
        }

        return ans;
    }
};