#include<iostream>
using namespace std;
int main()
{
int arr[5]={1,3,4,9,5};
int n,size,sum=0;
cout<<"enetr the array :";
cin>>n;
for(int i=0;i<n;i++)
//sum=n*(n+1)/2;
sum+=arr[i];
cout<<arr[i]<<" ";

}