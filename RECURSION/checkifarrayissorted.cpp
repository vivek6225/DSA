#include<bits/stdc++.h>
using namespace std;

// t.c = 0(n)
// s.c = 0(n)

 bool isSorted(vector<int> arr, int n){
  if(n == 0 || n ==1 ){ /// base case 
    return true;
  }
  return arr[n-1] >= arr[n-2] && isSorted(arr, n-1);

}
int main(){
  vector<int> arr = {1,2,8,4,5};
  cout<<isSorted(arr,arr.size()) <<endl;
  return 0;

}