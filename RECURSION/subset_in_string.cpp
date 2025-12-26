
// T.C = O(N * 2^N)
//S.C = 0(N)

#include<bits/stdc++.h>
using namespace std; 

  void subsets(string &s ,int index,int n,vector<string>&ans, string &temp){

    if(index == n){
      ans.push_back(temp);
      return;
    }

      // not include
      subsets(s,index+1,n,ans,temp);

      // include
      temp.push_back(s[index]);
      subsets(s,index+1,n,ans,temp);
      temp.pop_back();
  }

   int main(){
  string s = "abc";
  vector<string>ans; 
  string temp;
  subsets(s,0,s.size(),ans, temp);
  for(int  i = 0; i<ans.size();i++)
  cout<<ans[i]<<endl;

}