//---------optimal Approach--------------------------
// Time: O(n) 
// Space: O(1)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();              // size of array
        
        vector<int> ans(n, 1);            // initialize result with 1

        // --------- PREFIX PASS ----------
        // ans[i] will store product of all elements to the LEFT of i
        for(int i = 1; i < n; i++){
            ans[i] = ans[i-1] * nums[i-1];
        }

        // --------- SUFFIX PASS ----------
        int suffix = 1;                   // stores product of elements to the RIGHT
        
        for(int i = n - 2; i >= 0; i--){
            suffix *= nums[i+1];          // update suffix product
            
            ans[i] *= suffix;             // multiply prefix (already in ans[i]) with suffix
        }

        return ans;   // final result
    }
};
//---------Brute Force Approach--------------------------
// Time Complexity: O(n²)
// Space Complexity: O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();              // size of input array
        
        vector<int> ans(n, 0);            // result array

        // iterate for each index i
        for(int i = 0; i < n; i++){
            
            int product = 1;              // store product of all elements except nums[i]
            
            // loop through entire array
            for(int j = 0; j < n; j++){
                
                // skip the current index
                if(i != j){
                    product *= nums[j];   // multiply all other elements
                }
            }
            
            ans[i] = product;             // store result for index i
        }

        return ans;   // return final array
    }
};