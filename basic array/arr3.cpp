#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[10]={9,8,7,9,5,1,4};
    //int ans = INT_MAX;
    int ans=INT_MAX;
    for(int i=0;i<=10;i++)
    {
    if(arr[i]<=ans)
    ans=arr[i];
    }
    cout<<ans;
    return 0;
}
