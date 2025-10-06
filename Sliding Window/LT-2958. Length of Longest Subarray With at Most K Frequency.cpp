
// T.C = O(n)
// S.C = O(n)

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        int len = 0;  // To store the maximum length of valid subarray
        unordered_map<int, int> count;  // Frequency map for elements
        int start = 0, end = 0;
        int n = nums.size();

      
        while (end < n) {
            count[nums[end]]++;  // Include current element in window

            // If frequency of current element exceeds k, shrink window
            while (count[nums[end]] > k) {
                count[nums[start]]--;  // Decrease count of leftmost element
                start++;               // Move window start forward
            }

            // Update max length of valid subarray
            len = max(len, end - start + 1);

            end++;  // Expand window
        }

        return len;
    }
};