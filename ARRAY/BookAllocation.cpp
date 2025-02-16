#include<bits/stdc++.h>
using namespace std;
bool isValid(vector<int> arr,int n,int m, int maxAllowedPages){ // 0(n)
  int student = 1, page = 0;
  for(int i =0; i<n; i++){
    if(arr[i] > maxAllowedPages){
    return false;
  }
  if(page+arr[i] <= maxAllowedPages){
    page+=arr[i];
  }else{
    student++;
    page = arr[i];
  }
  }
  return student > m ?  false : true;
}


int allocationBooks(vector<int> &arr,int n,int m){  // 0(logN*n)
  if(m>n){
    return -1;
  }
  int sum = 0;
   for(int i= 0; i<n; i++){ //o(n)
    sum+= arr[i];
   }
   int ans = -1;
   int start = 0,end = sum;
   while(start < end){
    int mid = start + (end-start)/2;
    if(isValid(arr, n, m, mid)){  //left
     ans = mid;
     end = mid-1;
    }
    else { // right
    start = mid+1;
    }
   }
   return ans;
}

int main()
{
  vector<int> arr = {15,17,20};
 int n = 3, m = 2;

 cout<<allocationBooks(arr, n, m)<<endl;
 return 0;
  
}