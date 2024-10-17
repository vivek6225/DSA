#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n =  nums.size();
        vector<int>ans(n,1);
            //prefix = ans
            for(int i = 1; i<n; i++){
                ans[i] = ans[i-1] * nums[i-1];
            }
            //SUFFIX
            int suffix = 1;
            for(int i = n-2; i>=0; i--){
                suffix *= nums[i+1]; //ith suffix
                ans[i] *= suffix; 
            }
        return ans;  
    }
};