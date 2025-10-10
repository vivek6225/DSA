
//-------------Optimal Approach------------------------------

//Approach: Kadane’s Algorithm : 

// Continuously add elements to a running sum (currSum).
// If the sum becomes negative, it means this part of the array will not contribute to a larger sum, so we reset it to 0.

//T.C =0(n)
// S.C = 0(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int currSum = 0;          
        int maxSum = INT_MIN;     

        for (int i = 0; i < n; i++) {
            currSum += nums[i];               
            maxSum = max(maxSum, currSum); 

            // If current sum becomes negative, reset it to 0
            // (as negative sums will only reduce future subarray sums)
            if (currSum < 0)
                currSum = 0;
        }

        return maxSum; 
    }
};

//-------------Brute Force Approach------------------------
//T.C =0(n²)
// S.C = 0(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        int maxSum = INT_MIN; // initialize to smallest possible value

        // Outer loop → choose starting point
        for (int i = 0; i < n; i++) {
            int curSum = 0;

            // Inner loop → choose ending point and calculate subarray sum
            for (int j = i; j < n; j++) {
                curSum += nums[j]; // accumulate sum
                maxSum = max(maxSum, curSum); // update maximum sum
            }
        }

        return maxSum;
    }
};
