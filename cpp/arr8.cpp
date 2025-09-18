#include<iostream>
using namespace std;
int main()
{
    int arr[5]={66,7,111,99,11};
    int index;
    int num,n;
    cout<<"enter the arry";
   cin>>n;
    for(int i=0;i<5 ;i++)
    if(arr [i]==num)
    {
    index=i;
    break;
}
    cout<<index;
}