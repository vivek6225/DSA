#include<bits/stdc++.h>
using namespace std;
int power(int n,int num){
    // if(n==1)
    // {
    
    //     return num;
    // }
      if(n==0)
    {
    
        return num;
    }
    
    return num*power(num,n-1);
}
int main()
{
    int n;
    cout<<"enter the number :"<<endl;
    cin>>n;
    cout<<power(2,n);
}