#include<bits/stdc++.h>
using namespace std;
 bool ispossibe()
  int getDistance(vector<int> &arr,int N,int c){
    sort(arr.begin(),arr.end());
    int start = 1, end = arr[N-1] - arr[0] ,ans = -1;

    while(start < end){

    int mid = start + (end-start)/2;
    if(ispossible(arr,N,c,mid)){
      ans = mid;
      start = mid+1;
    }else{
      end = mid-1;
    }
 
  }
  return ans;
}
int main(){

}