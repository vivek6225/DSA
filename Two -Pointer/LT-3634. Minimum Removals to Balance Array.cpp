// T.C = O(nlogn)
// S.C = O(1)
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {

        int n = nums.size();

        // Sort array so that:
        // nums[i] = minimum in window
        // nums[j] = maximum in window
        sort(nums.begin(), nums.end());

        // Stores largest valid window size
        int L = 1;

        // Sliding window pointers
        int i = 0;
        int j = 0;

        while(j < n) {

            // If condition becomes invalid:
            // max > min * k
            // shrink window from left side
            while(i < j && nums[j] > 1LL * k * nums[i]) {
                i++;
            }

            // Update largest valid window length
            L = max(L, j - i + 1);

            // Expand window
            j++;
        }

        // Minimum removals =
        // total elements - largest valid window
        return n - L;
    }
};