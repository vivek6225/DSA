#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cout<<"enter the number : ";
  cin>>n;
  int arr[1000];
  //first number 0
  //second number 1

   arr[0] = 0;
   arr[1] = 1;
   for (int i = 2; i<=n-1; i++)
   arr[i] =  arr[i-1]+ arr[i-2];
   cout<<"fibonacci series : "<<arr[n-1]<<" ";
  
}