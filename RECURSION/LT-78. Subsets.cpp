  // S.c = 0(n)
    //T.c = 0(2^n)
       
  class Solution {
public:

    // This function generates all subsets using recursion
    void subsets(vector<int> arr, int index, int n,
                 vector<vector<int>>& ans, vector<int> &temp) {

        // If we have processed all elements,
        // store the current subset in answer
        if (n == index) {
            ans.push_back(temp);
            return;
        }

        // -------- Choice 1: Do NOT include arr[index] --------
        // Move to next index without adding current element
        subsets(arr, index + 1, n, ans, temp);

        // -------- Choice 2: Include arr[index] --------
        temp.push_back(arr[index]);        // take the element

        // Move to next index after including it
        subsets(arr, index + 1, n, ans, temp);

        // -------- Backtracking step --------
        // Remove the element that we just added,
        // so that temp is restored for other recursive paths
        temp.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;   // to store all subsets
        vector<int> temp;         // to build current subset

        // Start recursion from first index (0)
        subsets(nums, 0, nums.size(), ans, temp);

        return ans;
    }
};