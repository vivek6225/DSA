#include<bits/stdc++.h>
using namespace std;
int main()
{
int arr[1000];
int n;
cout<<"enter the size of array  = ";
cin>>n;
cout<<"Enter the element = ";
for(int i = 0; i<n; i++)
cin>>arr[i];

  for(int start = 0; start<n; start++){
    for(int end = start; end<n; end++){
      for(int i = start; i<=end;i++){
        cout<<arr[i];
      }
      cout<<" ";
    }
    cout<<endl;
  }
  return 0;
}