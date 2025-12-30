
// T.C = 0(n!*n)
 // S.C = 0(n!)

  class Solution {
public:

    void permut(vector<int>& arr, vector<vector<int>>& ans, int index) {

        // Base case:
        // If index reaches the end, current permutation is ready
        if(arr.size() == index){
            ans.push_back(arr);
            return;
        }

        // Try every element from index to end as current position
        for(int i = index; i < arr.size(); i++){

            // Fix element arr[i] at current index
            swap(arr[index], arr[i]);

            // Recursively generate permutations for next index
            permut(arr, ans, index + 1);

            // Backtrack: restore original order
            swap(arr[index], arr[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        // Start generating permutations from index 0
        permut(nums, ans, 0);
        return ans;
    }
};