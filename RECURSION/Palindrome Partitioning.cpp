//1. Goal: Break string into all palindrome-only partitions.
//2. ispalin(s): Checks if a string is a palindrome.
// 3. If part is palindrome → add to current list.
// Recurse on remaining string.
// Backtrack after recursion.
// Backtracking used to explore all valid splits.
// Result stored in ans.
class Solution {
  public:
  bool ispalin(string s){
      string s2 = s;
      reverse(s.begin(),s.end());
      return s == s2;
  
  }
  void getAllparts(string s,vector<string>&partitions,vector<vector<string>>&ans){
      if(s.size() == 0){
          ans.push_back(partitions);
          return;
      }
      for(int  i = 0; i<s.size();i++){
         string parts = s.substr(0,i+1);
         if(ispalin(parts)){
          partitions.push_back(parts);
          getAllparts(s.substr(i+1) ,partitions,ans);
          partitions.pop_back();
         }
      }
  }
      
      vector<vector<string>> partition(string s) {
          vector<vector<string>>ans;
          vector<string>partitions;
          getAllparts(s,partitions,ans);
          return ans;
          
      }
  };