//-------optimal  Approach-----------------
// Time Complexity : O(n log n)
// Space Complexity: O(1)
class Solution {
public:
    int minPairSum(vector<int>& nums) {

        int n = nums.size();

        // Sort the array
        sort(nums.begin(), nums.end());

        // Two pointers
        int start = 0;
        int end = n - 1;

        // Store maximum pair sum
        int ans = 0;

        while(start < end) {

            // Pair smallest with largest
            int pairSum = nums[start] + nums[end];

            // Update maximum pair sum
            ans = max(ans, pairSum);

            // Move pointers
            start++;
            end--;
        }

        return ans;
    }
};

//-------Better Approach-----------------
// Time Complexity : O(n log n)
// Space Complexity: O(n)

class Solution {
public:
    int minPairSum(vector<int>& nums) {

        // Sort the array
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // Store all pair sums
        vector<int> pairSums;

        // Pair smallest with largest
        for(int i = 0; i < n / 2; i++) {

            int sum = nums[i] + nums[n - 1 - i];

            pairSums.push_back(sum);
        }

        // Find maximum pair sum
        int maxi = 0;

        for(int i = 0; i < pairSums.size(); i++) {

            if(pairSums[i] > maxi) {
                maxi = pairSums[i];
            }
        }

        return maxi;
    }
};