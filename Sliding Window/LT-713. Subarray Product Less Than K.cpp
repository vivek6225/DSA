//----------------Optimal Approach---------------------------------

                // # Approach
// 1. Use two pointers `start` and `end` to maintain a sliding window.
// 2. Keep a running product of elements inside the window.
// 3. Expand the window by multiplying `nums[end]`.
// 4. If product becomes greater than or equal to `k`, shrink the window from the left.
// 5. For every valid window, add `(end - start + 1)` to the answer because all subarrays ending at `end` are valid.
// 6. Continue until `end` reaches the end of the array.
// Time Complexity  : O(n)
// Space Complexity : O(1)

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        // Edge case
        if(k <= 1)
            return 0;

        int n = nums.size();

        // Sliding window pointers
        int start = 0;
        int end = 0;

        // Store count of valid subarrays
        int count = 0;

        // Store product of current window
        int product = 1;

        while(end < n) {

            // Include current element in product
            product *= nums[end];

            // Shrink window if product becomes >= k
            while(product >= k && start <= end) {

                product /= nums[start];

                start++;
            }

            // Count all valid subarrays
            // ending at 'end'
            count += (end - start + 1);

            // Move window forward
            end++;
        }

        return count;
    }
};
//----------------Better  Approach----------------------
// T.C = 0(n²) 
// S.C = 0(1)
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int total = 0;

        for (int i = 0; i < n; i++) {
            int product = 1;  // should start with 1
            for (int j = i; j < n; j++) { 
                product *= nums[j];
                if (product < k) {
                    total++;
                } else {
                    break; // optimization, no need to check further
                }
            }
        }

        return total;
    }
};