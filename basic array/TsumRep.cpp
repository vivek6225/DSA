#include<bits/stdc++.h>
using namespace std;
int subset(int arr[],int index,int n,int sum)
{
    if(sum==0)
    return 1;
    if(index==n||sum<0)
    return 0;
    return subset(arr,index+1,n,sum)+subset(arr,index,n,sum-arr[index]);
}
int main()
{
    int arr[]={2,3,4};
    int sum  = 6;
    cout<<subset(arr,0,3,sum)<<endl;
}