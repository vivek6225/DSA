#include<bits/stdc++.h>
using namespace std;
bool ispossible(vector<int> arr,int n, int m,int maxAllowedtime){
int painters = 1, time = 0;
for(int i = 0; i<n; i++){
if(time + arr[i] <= maxAllowedtime){
   time += arr[i];
}else{
painters++;
time = arr[i];
}
}
return painters <= m;
}

int minTimetopaint(vector<int> &arr, int n, int m ){
  int sum = 0 , maxVal = INT_MIN;
  for(int i  = 0; i<n; i++){
    sum += arr[i];
    maxVal = max(maxVal,arr[i]);
  }
int start = maxVal , end = sum, ans = -1;
while(start < end){
  int mid = start + (end-start)/2;
  if(ispossible(arr,n,m,mid)){ // left
  ans = mid;
  end = mid-1;
   } else{ //right
    start = mid+1;
   }

}
return ans;

}
int main(){
  vector<int>arr = {40,30,10,20};
  int n = 4, m = 2;
  cout << minTimetopaint(arr, n, m) << endl;
  return 0;
}
