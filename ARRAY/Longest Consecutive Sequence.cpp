#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        //OPTIMAL APPROACH
          // Optimal approach using unordered_set for O(1) lookup

        if(nums.empty()) return 0;
        int n = nums.size();
        int longest = 0;
        unordered_set<int>st(nums.begin(), nums.end());// Insert all elements at once
       for(int num : st){

          // Only start a new sequence if num - 1 is not in the set

        if(st.find(num - 1) == st.end()){
       int count = 1;
        int currentNum = num; 
          // Count the length of the current consecutive sequence 
          
       while(st.find( currentNum+1) != st.end()){
       currentNum += 1;
        count = count+1;
       }
       longest = max(longest,count);         
        }

       }
          return longest;
       
        
    }
};