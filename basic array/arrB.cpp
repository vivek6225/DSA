#include<iostream>
using namespace std;
int main()
{
    int arr[1000];
    int n,i,j;
    cout<<"Enter the size of array";
    cin>>n;
    cout<<"Enter the element of array";
    for(i=0;i<n;i++){
    cin>>arr[i];
    }
    for( i=n-2;i>0;i--)
    {
        bool swaped = 0;
        for(j=0;j<=i;j++)
        {
            if(arr[j]>arr[i])
            {
                swaped = 1;
                swap(arr[j],arr[i]);

            }
        }
        if (swaped == 0)
        break; 
    }
     for(i=0;i<n;i++)
     {
        cout<<arr[i]<<" ";
     }


}