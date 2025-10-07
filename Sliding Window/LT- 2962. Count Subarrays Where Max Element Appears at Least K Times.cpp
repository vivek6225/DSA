
//T.C: O(N)
//S.C: O(1)

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Step 1: Find the maximum element in the array
        int maxEl = 0;
        for (int i = 0; i < n; i++) {
            maxEl = max(maxEl, nums[i]);
        }

        // Step 2: Initialize window pointers and counters
        int start = 0, end = 0;
        int count = 0;      // count how many times maxEl appears in current window
        long long total = 0;    // total valid subarrays count

        // Step 3: Expand the window with 'end' pointer
        while (end < n) {
            if (nums[end] == maxEl)
                count++; // Found one occurrence of maxEl

            // Step 4: Shrink window from left until maxEl count < k
            // When we have k occurrences, every subarray starting from 'start'
            // to any index >= end will be valid, so we add (n - end)
            while (count == k) {
                total += n - end;

                // Shrink from left side
                if (nums[start] == maxEl)
                    count--; // Decrease maxEl count if it's removed
                start++;
            }

            // Move 'end' to expand the window
            end++;
        }

        return total;
    }
};