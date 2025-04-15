//use[arr[i] + 10] checks if the current number has already been used at this level.
//FIND INDX = whatever numberit is,add 10 to it.   2+10=12(index)

class Solution {
  public:
  void permut(vector<int>&arr,vector<vector<int>>&ans,int index){
      if( index == arr.size()){
          ans.push_back(arr);
          return ;
      }
      vector<bool>use(21,0);
      for(int i = index; i<arr.size(); i++){
         if(use[arr[i]+10] == 0){
          swap(arr[i],arr[index]);
          permut(arr,ans,index+1);
          swap(arr[i],arr[index]);
          use[arr[i]+10] = 1;
         }
      }
  }
      vector<vector<int>> permuteUnique(vector<int>& nums) {
          vector<vector<int>>ans;
          permut(nums,ans,0);
          return ans;
      }
  };