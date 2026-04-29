//---------Optimal Approach----------------------
// Time: O(n) 
// Space: O(1) 
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();        // total number of lines
        int maxWater = 0;             // stores maximum water

        int lp = 0, rp = n - 1;       // left pointer and right pointer

        // loop until both pointers meet
        while(lp < rp){
            
            int width = rp - lp;     // distance between two lines
            
            // height is limited by the smaller line
            int ht = min(height[lp], height[rp]);
             
            int currWater = width * ht;   // current area
            
            // update maximum water
            maxWater = max(maxWater, currWater);
            
            // move the pointer pointing to smaller height
            // because increasing smaller height may increase area
            if(height[lp] < height[rp]) {
                lp++;   // move left pointer forward
            } else {
                rp--;   // move right pointer backward
            }
        }

        return maxWater;   // final maximum area
    }
};
//-------------------Brute Force Approach------------------
// Time Complexity = O(n²)   (because of two loops)
  //Space Complexity = O(1)   (constant extra space)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();          // total number of lines
        int maxWater = 0;               // to store maximum water

        // pick first line
        for(int i = 0; i < n; i++){
            
            // pick second line (after i)
            for(int j = i + 1; j < n; j++){
                
                int width = j - i;   // distance between two lines
                
                // height is decided by smaller line
                int Ht = min(height[i], height[j]);
                
                // area = width * height
                int currWater = width * Ht;
                
                // update maximum water if current is greater
                maxWater = max(maxWater, currWater);
            }
        }

        return maxWater;  // final answer
    }
};