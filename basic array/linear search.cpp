#include<iostream>
using namespace std;
int main()
{
    int arr[1000];
    int n,beg=0,mid,end=n-1,key,i;
    cout<<"Enter the number of array";
    cin>>n;
    cout<<"enter the element of array";
    for(i=0;i<n;i++)
    cin>>arr[i];
    cout<<"Enter the key :";
    cin>>key;
   

    while(beg<=end)
    {

    mid = (beg+end)/2;
    if(arr[mid]==key){
    
        return mid ;
    }
     else if(arr[mid]<key)
    {
    beg= mid+1;
    }

    else 
    
    {
    end = mid-1;
    }
    
   if (mid ==1);
  cout<<"element  found";
   
else
  cout<<"element not found";
  }
   }

