#include<iostream>
using namespace std;
int main()
{
    
    int arr[4]={3,4,5,6,};
    int sum=0;
    int length=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<length;i++)
    
    sum=sum+arr[i];
    
    cout<<sum<<" ";
}