#include<bits/stdc++.h>
using namespace std;
int fact(int n){
    if(n==1||n==0)
    {
        return 1;
    }
    return n*fact(n-1); 
}
int main()
{
    int n;
    cout<<"enter the number : "<<endl;
    cin>>n;
    if(n<0)
    {
        cout<<"factorial is not possible";
        return 0;
    }
    cout<<fact(n);
    return 1;
   

}