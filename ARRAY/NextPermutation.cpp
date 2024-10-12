#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        int n = nums.size();

         // Step 1: Find the first decreasing element from the right

        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }
          // If no such element is found, reverse the entire array

        if(index == -1){
            reverse(nums.begin(),nums.end());
            return ;
        }
          // Step 2: Find the next larger element to swap with nums[index]
          
        for(int i = n-1; i>index; i--){
            if(nums[i] > nums[index]){
                swap(nums[i],nums[index]);
                break;

            }
        }

        // Step 3: Reverse the elements after the swapped index
        
         reverse(nums.begin() + index + 1, nums.end());
         return ;   
    }
};