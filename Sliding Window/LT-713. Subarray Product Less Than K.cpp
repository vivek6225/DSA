//----------------Optimal Approach---------------------------------
//            Approach (Sliding Window):
// 1.Keep a running product of elements in the current window [start...end].
// 2Expand the window by moving end forward.
// 3.If product ≥ k, shrink from the left by moving start until product < k.
// 4.At each step, all subarrays ending at end and starting from start to end are valid.
//      .That’s (end - start + 1) subarrays.
// 5.Add that count to the result.

//T.C = 0(n)
//S.C = 0(1)

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int start = 0, end = 0;   // sliding window pointers
        int count = 0;            // to store result
        int product = 1;          // running product of current window

        while (end < n) {
            product *= nums[end];  // expand the window by including nums[end]

            // If product becomes >= k, shrink window from the left
            while (product >= k && start <= end) {
                product /= nums[start];
                start++;
            }

            // All subarrays ending at 'end' and starting from [start...end]
            // will have product < k
            // Number of such subarrays = (end - start + 1)
            count += (end - start + 1);

            end++; // move window forward
        }
        return count;
    }
};
//----------------Brute Force Approach-----------------------------
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