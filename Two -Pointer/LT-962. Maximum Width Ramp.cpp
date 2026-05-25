//------------ Optimal Approach ---------------------
// T.C = O(n)
// S.C = O(n)
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {

        int n = nums.size();

        // rightMax[i] stores maximum value from i to n-1
        vector<int> rightMax(n);

        rightMax[n - 1] = nums[n - 1];

        // Build suffix maximum array
        for(int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], nums[i]);
        }

        int ramp = 0;

        int i = 0;
        int j = 0;

        while(j < n) {

            // Move i until valid ramp becomes possible
            while(i < j && nums[i] > rightMax[j]) {
                i++;
            }

            // Update maximum width
            ramp = max(ramp, j - i);

            j++;
        }

        return ramp;
    }
};
//------------ Better Approach ---------------------
// T.C = O(n²) in the worst case
//S.C = O(1)
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {

        int n = nums.size();
        int ramp = 0;

        // Try every index as starting point
        for(int i = 0; i < n; i++) {

            // Start from farthest right side
            for(int j = n - 1; j > i; j--) {

                // Valid ramp condition
                if(nums[i] <= nums[j]) {

                    // Update maximum width
                    ramp = max(ramp, j - i);

                    // Since we are moving from right to left,
                    // this is the maximum width possible for current i
                    break;
                }
            }
        }

        return ramp;
    }
};
//--------- Brute Force Approach -----------------
//T.C  = O(N)
//S.C  = O(1)
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        int ramp = 0;

        for(int i = 0; i < n; i++) {

            for(int j = i; j < n; j++) {

                // Valid ramp condition
                if(i < j && nums[i] <= nums[j]) {

                    // Store maximum width
                    ramp = max(ramp, j - i);
                }
            }
        }

        return ramp;
    }
};