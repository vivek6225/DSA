#include<bits/stdc++.h>
using namespace std;

bool divide(vector<int>arr)
{
   int prefix=0 , total_sum=0,n=arr.size();

   for(int i=0;i<n;i++)
   total_sum+=arr[i];

   for(int i=0;i<n;i++)
   {
    //prefix+=arr[i];

    // int ans = total_sum-prefix;
    // if(ans==prefix)

    prefix+=arr[i];
    if (total_sum==2*prefix)
    return 1;
   }

   return 0;
}
int main()
{
    int n;
    cout<<"enter the size of array :";
    cin>>n;
    vector<int>v(n);
    cout<<"enter the element array :";
    for(int i=0;i<n;i++)
    cin>>v[i];

    cout<<divide(v);
}