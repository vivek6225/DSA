              //Optimal Approach
              // S.C= 0(N)
              // T.C= 0(1)
    class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       int n =  nums.size();
       k = k % n; // in case k is greater the size of the array
       
       //revertse the entire array
       reverse(nums.begin(),nums.end());

       //reverse first k element
       reverse(nums.begin(),nums.begin()+k);

       //reverse the remaining element
       reverse(nums.begin()+k,nums.end());  
    }
};  
            
//-----------------------------------------------------------------------------------------
                       // Brute Force Approach
              // T.C = O(N)
              // S.C = O(N)
           class Solution {
           public:
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // handle k > n
        vector<int> ans;

        // Step 1: store last k elements
        for (int i = n - k; i < n; i++) {
            ans.push_back(nums[i]);
        }

        // Step 2: store first n-k elements
        for (int i = 0; i < n - k; i++) {
            ans.push_back(nums[i]);
        }

        // Step 3: copy ans back to nums
        for (int i = 0; i < n; i++) {
            nums[i] = ans[i];
        }
    }
};
