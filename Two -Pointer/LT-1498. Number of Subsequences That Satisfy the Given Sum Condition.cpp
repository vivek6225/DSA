//----------------Optimal approach-----------------

// Time Complexity	O(n log n)
// Space Complexity	O(n)
class Solution {
public:

    // Mod value to avoid overflow
    int M = 1e9 + 7;

    int numSubseq(vector<int>& nums, int target) {

        // Size of array
        int n = nums.size();

        // Sort the array
        // So we can use two pointers
        sort(nums.begin(), nums.end());

        // power[i] stores 2^i % M
        vector<int> power(n);

        // 2^0 = 1
        power[0] = 1;

        // Precompute powers of 2
        for(int i = 1; i < n; i++) {
            power[i] = (power[i - 1] * 2) % M;
        }

        // Two pointers
        int l = 0;
        int r = n - 1;

        // Stores final answer
        long long result = 0;

        while(l <= r) {

            // Check if minimum + maximum <= target
            if(nums[l] + nums[r] <= target) {

                // Count all possible subsequences
                // between l and r
                // Total = 2^(r-l)
                result = (result + power[r - l]) % M;

                // Move left pointer forward
                l++;
            }
            else {

                // Sum too large
                // Reduce maximum element
                r--;
            }
        }

        // Return final answer
        return result;
    }
};
//----------------brute force approach-------------
// Time Complexity	O(2ⁿ × n)
// Space Complexity	O(n)

                     // USING RECURSION
class Solution {
public:

    // Stores count of valid subsequences
    int count = 0;

    // Recursive function to generate all subsequences
    void solve(int index, vector<int>& nums,
               vector<int>& temp, int target) {

        // Base case:
        // When all elements are processed
        if(index == nums.size()) {

            // Ignore empty subsequence
            if(temp.size() == 0) {
                return;
            }

            // Initialize min and max with first element
            int mini = temp[0];
            int maxi = temp[0];

            // Find minimum and maximum element
            // in current subsequence
            for(int i = 0; i < temp.size(); i++) {

                if(temp[i] < mini) {
                    mini = temp[i];
                }

                if(temp[i] > maxi) {
                    maxi = temp[i];
                }
            }

            // Check condition:
            // minimum + maximum <= target
            if(mini + maxi <= target) {
                count++;
            }

            return;
        }

        // ----------TAKE ------

        // Include current element in subsequence
        temp.push_back(nums[index]);

        // Move to next index
        solve(index + 1, nums, temp, target);

        // --------BACKTRACK -------

        // Remove last inserted element
        temp.pop_back();

        // -----------NOT TAKE -----

        // Skip current element
        solve(index + 1, nums, temp, target);
    }

    int numSubseq(vector<int>& nums, int target) {

        // Temporary vector to store subsequence
        vector<int> temp;

        // Start recursion from index 0
        solve(0, nums, temp, target);

        // Return total valid subsequences
        return count;
    }
};