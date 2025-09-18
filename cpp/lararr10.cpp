#include<iostream>
#include<limits.h>
using namespace std;
int main()
{
    int arr[6]={3,6,9,12,15,4};
    int n;
    int ans = INT_MIN;
    for(int i=0;i<5;i++)
    {
        if(arr[i]>ans)
        ans=arr[i];
        cout<<ans<<" ";
    
        
    }
    

}
