#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        //OPTIMAL APPROACH
        // T.C = O(N)
        int maxWater = 0;
        int lp = 0, rp = height.size()-1;
        while(lp < rp){  // lp= leftPointer, rp= rightpointer
             int width = rp - lp;
             int ht = min(height[lp],height[rp]);
             int currWater = width * ht;
             maxWater = max(maxWater,currWater);
             height[lp] < height[rp] ? lp++ : rp--; 
        }   
        return maxWater;
        
    }
};