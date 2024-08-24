#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cout<<"enter the size of array : ";
cin>>n;
  int arr[n];
  cout<<"enter the element of array : ";
  for(int i=0; i<n; i++)
  cin>>arr[i];


int start = 0,end = n-1;
    while (start<end){
      swap (arr[start],arr[end]);
      start++;
      end--;
    };
        cout<<"reverse array : ";
      for(int i=0; i<n; i++)
      cout<<arr[i]<<" ";   
}