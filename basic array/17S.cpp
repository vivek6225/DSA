#include<iostream>
using namespace std;
int main()
{
    int arr[100];
    int n,i,square,mid,ans,start=0,end=square,target;
    cout<<"Enter the size of array";
    cin>>n;
    cout<<"enter the array";
    for(i=0;i<n;i++)
    cin>>arr[i];
    cout<<"enter the target";
    cin>>target;
    while(start<=end)
    {
        mid = start+(end-start)/2;
        if(mid*mid==square)
        {
        cout<<mid; 
        break;
    }

    else if(mid*mid<square)
    {
        ans=mid;
        start=mid+1;
    }
    else 
    end=mid-1;
    }
    cout<<ans<<" ";
}