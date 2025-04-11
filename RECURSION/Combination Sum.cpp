// 1.Include current element once: indx + 1
// 2.Include current element again: indx
// 3.Skip current element: indx + 1
// 4. Use set<vector<int>> to avoid duplicates.
//After including an element, always pop_back() to undo the choice.

class Solution {
  public:
  set<vector<int>> s;
    void getAllcombinations(vector<int>&arr,int indx, int tar, vector<vector<int>> &ans,vector<int>&combin){
      if(indx == arr.size() || tar < 0){
      return ;
      }
      if(tar == 0){
          if(s.find(combin) == s.end()){
              ans.push_back(combin);
              s.insert(combin);
          }
          return;
      }
      //single 
      combin.push_back(arr[indx]);
      getAllcombinations(arr,indx+1,tar-arr[indx],ans,combin);
      //multiple
      getAllcombinations(arr,indx,tar-arr[indx],ans,combin);
      combin.pop_back(); // backtracking
      getAllcombinations(arr,indx+1,tar,ans,combin);
   }
      vector<vector<int>> combinationSum(vector<int>& arr, int target) {
     vector<vector<int>>ans;
     vector<int>combin;
     getAllcombinations(arr,0,target,ans,combin);
     return ans;
          
      }

  };