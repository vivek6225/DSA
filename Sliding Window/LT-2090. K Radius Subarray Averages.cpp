//----------------Optimal Approach------------------
// Time Complexity: O(n)
// Space Complexity: O(n) 
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();

        // If k = 0, each element is its own average
        if (k == 0) {
            return nums;
        }

        // Initialize answer array with -1
        vector<int> result(n, -1);

        // Not enough elements to form a window of size (2*k + 1)
        if (n < 2 * k + 1) {
            return result;
        }

        // Build prefix sum array
        vector<long long> prefixSum(n, 0);
        prefixSum[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        // Iterate through all valid center indices
        for (int i = k; i < n - k; i++) {

            int left_index = i - k;
            int right_index = i + k;

            // Sum of elements from left_index to right_index
            long long sum = prefixSum[right_index];

            // Remove prefix before left_index
            if (left_index > 0) {
                sum -= prefixSum[left_index - 1];
            }

            // Store the average of the current window
            result[i] = sum / (2 * k + 1);
        }

        return result;
    }
};
//--------Brute Force approach----------------
// Time Complexity: O(nk)
// Space Complexity: O(n) 
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {

            // Not enough elements on either side
            if (i - k < 0 || i + k >= n) {
                continue;
            }

            long long sum = 0;

            // Calculate sum of subarray [i-k, i+k]
            for (int j = i - k; j <= i + k; j++) {
                sum += nums[j];
            }

            // Store average
            ans[i] = sum / (2 * k + 1);
        }

        return ans;
    }
};