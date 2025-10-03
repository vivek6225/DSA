
//---------------Optimal Approach---------------------------------
//Time Complexity: O(n)
//Space Complexity: O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        int start = 0, end = 0;   
        int sum = 0;              
        int total = INT_MAX;     

        // Expand the window by moving 'end'
        while(end < n){
            sum += nums[end];  

            // Shrink the window from 'start' while sum >= target
            while(sum >= target){
                // update minimum length of window
                total = min(total, end - start + 1);

                // remove leftmost element and shrink the window
                sum -= nums[start];
                start++;
            }

            // move 'end' forward to expand the window
            end++;
        } 

        // If total was never updated, no subarray found → return 0
        return total == INT_MAX ? 0 : total;
    }
};

//---------------Brute Force Approach------------------------------
//T.C = 0(n²)
// S.C = 0(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLen = INT_MAX;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j]; 
                if (sum >= target) {
                    minLen = min(minLen, j - i + 1); //  update minimum length
                    break; // no need to check longer subarrays from same i
                }
            }
        }

        return (minLen == INT_MAX) ? 0 : minLen; // if no subarray found, return 0
    }
};
