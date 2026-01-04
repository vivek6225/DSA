
// T.C = 0(N)
//S.C = 0(H)

class Solution {
public:
    // This function builds a height-balanced BST from sorted array
    // start and end represent current subarray range
    TreeNode* ArrayToBST(vector<int>& arr, int start, int end){

        if(start > end)
            return NULL;                 // base case

        // find middle element to keep tree balanced
        int mid = start + (end - start) / 2;

        // create root node from middle element
        TreeNode* root = new TreeNode(arr[mid]);

        // build left subtree from left half
        root->left  = ArrayToBST(arr, start, mid - 1);

        // build right subtree from right half
        root->right = ArrayToBST(arr, mid + 1, end);

        return root;                    // return constructed subtree
    }

    // Main function to convert sorted array into height balanced BST
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        return ArrayToBST(nums, 0, nums.size() - 1);   // start recursion
    }
};
