#include<iostream>
using namespace std;
int main()
{
    int arr[5]={1,2,3,4,5};
    int n;
    cout<<"enter the array";
   cin>>n;
    for( int i=0;i<n;i+=2){
    cout<< arr[i]<<" ";
    } 
    return 0;
}