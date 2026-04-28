//-------------------optimal Approach----------------------
// Time Complexity = O(n)
// Space Complexity = O(1)
class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();       // size of array
        int water = 0;               // total trapped water

        int l = 0, r = n - 1;        // two pointers: left and right
        int leftmax = 0, rightmax = 0; // max height seen so far from left and right

        // move both pointers towards each other
        while(l < r){

            // update left and right maximums
            leftmax  = max(leftmax, height[l]);
            rightmax = max(rightmax, height[r]);

            // decide which side to process
            if(leftmax < rightmax){
                // left side is smaller → it limits water

                // water stored = left boundary - current height
                water += leftmax - height[l];

                l++; // move left pointer
            } 
            else{
                // right side is smaller → it limits water

                // water stored = right boundary - current height
                water += rightmax - height[r];

                r--; // move right pointer
            }
        }

        return water; // total trapped water
    }
};

//-------------------Beter Approach----------------------------------------
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