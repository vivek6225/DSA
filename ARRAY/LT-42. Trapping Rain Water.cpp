//----------------Brute force approach-------------------------
// Time: O(n²) 
// Space: O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int totalWater = 0;

        for(int i = 0; i < n; i++) {
            int leftmax = 0, rightmax = 0;

            // find left max
            for(int j = 0; j <= i; j++) {
                leftmax = max(leftmax, height[j]);
            }

            // find right max
            for(int j = i; j < n; j++) {
                rightmax = max(rightmax, height[j]);
            }

            // water at index i
            totalWater += min(leftmax, rightmax) - height[i];
        }

        return totalWater;
    }
};
//--------Beter Approach----------------------------------------
// Time Complexity = O(n)
// Space Complexity = O(n)
class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();        // size of the height array
        int water = 0;                // variable to store total trapped water

        // arrays to store maximum height from left and right
        vector<int> leftmax(n), rightmax(n);

        // first element leftmax is same as height
        leftmax[0] = height[0];

        // fill leftmax array
        // leftmax[i] = maximum height from index 0 to i
        for(int i = 1; i < n; i++){
            leftmax[i] = max(leftmax[i-1], height[i]);
        }

        // last element rightmax is same as height
        rightmax[n-1] = height[n-1];

        // fill rightmax array
        // rightmax[i] = maximum height from index i to n-1
        for(int i = n-2; i >= 0; i--){
            rightmax[i] = max(rightmax[i+1], height[i]);
        }

        // calculate trapped water at each index
        for(int i = 0; i < n; i++){

            // water level depends on smaller boundary
            int miniHeight = min(leftmax[i], rightmax[i]);

            // trapped water = boundary height - current height
            water += miniHeight - height[i];
        }

        return water;   // return total trapped water
    }
};