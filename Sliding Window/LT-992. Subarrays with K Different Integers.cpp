
//----------------brute force approach---------------------------
// Time Complexity: O(n²)
// Space Complexity: O(k)

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int total = 0;
        
        // Outer loop → select the starting index of the subarray
        for (int i = 0; i < n; i++) {
   // Use a set to track distinct integers in the current subarray
             unordered_set<int> distinct;

            // Inner loop → expand the subarray to the right
            for (int j = i; j < n; j++) {
                distinct.insert(nums[j]); // add current element to the set

                // if number of distinct elements exceeds k, break
                if (distinct.size() > k) break;

              // if number of distinct elements equals k, count it
                if (distinct.size() == k)
                    total++;
            }
        }

        return total;
    }
};