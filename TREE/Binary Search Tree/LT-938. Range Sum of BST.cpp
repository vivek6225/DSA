
// T.C = O(N)
// T.C = O(H)

int n1, n2;   // global variables

class Solution {
public:
   
    void find(TreeNode* root, int &sum){

        if(!root)
            return;

        // If both limits are smaller, go left
        if(root->val > n1 && root->val > n2)
            find(root->left, sum);

        // If both limits are larger, go right
        else if(root->val < n1 && root->val < n2)
            find(root->right, sum);

        else{
            // Node is in range
            find(root->left, sum);
            sum += root->val;
            find(root->right, sum);
        }
    }

    int rangeSumBST(TreeNode* root, int low, int high) {

        n1 = low;
        n2 = high;

        int sum = 0;
        find(root, sum);

        return sum;
    }
};