// t.c = 0(n!*n)
 // s.s = 0(n!)

 class Solution {
    public:
        void permut(vector<int>&arr,vector<vector<int> >&ans,int index)
            {
                if(arr.size()==index) // base case
                {
                    ans.push_back(arr);
                    return;            
            }
            for(int i=index; i<arr.size(); i++)
            {
                swap(arr[index],arr[i]);
                permut(arr,ans,index+1);
                swap(arr[index],arr[i]); // backtrack
              
            }
            }
        vector<vector<int>> permute(vector<int>& nums) {
            
                vector<vector<int>>ans;
               permut(nums,ans,0); 
               return ans; 
            
            
        }
    };