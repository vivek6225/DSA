#include<bits/stdc++.h>
using namespace std;

void print ( int num, int N){
    if(num==N)
    {
        cout<<num<<endl;
        return;
    }
    cout<<num<<endl;
    print(num+1,N);
}

int main()
{
    int N;
    cin>>N; 
    print(1,N);
}