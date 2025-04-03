class Solution {
  public:
         
         // t.c = 0(n!*n)
         // s.s = 0(n!)
   
      void permut(vector<int>&arr,vector<vector<int> >&ans,int index)
          {
              if(arr.size()==index)
              {
                  ans.push_back(arr);
                  return;            
          }
          for(int i=index; i<arr.size(); i++)
          {
              swap(arr[index],arr[i]);
              permut(arr,ans,index+1);
              swap(arr[index],arr[i]);
            
          }
          }
      vector<vector<int>> permute(vector<int>& nums) {
          
              vector<vector<int>>ans;
             permut(nums,ans,0); 
             return ans; 
          
          
      }
  };