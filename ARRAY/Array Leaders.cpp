#include<bits/stdc++.h>
using namespace std;
class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(int n, int arr[]) {
        
        // Code here
     vector<int>ans;
      int maxi = INT_MIN;
      
      // Traverse the array from right to left
      for(int i = n-1; i>=0; i--){
          if(arr[i] >= maxi){
              ans.push_back(arr[i]);
          
          maxi = arr[i]; // Update the current maximum
          }
      }
          // The result is in reverse order, so reverse it before returning
      reverse(ans.begin(),ans.end());
      return ans;
    }
    
};