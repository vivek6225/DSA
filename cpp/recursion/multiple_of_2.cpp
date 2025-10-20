#include<bits/stdc++.h>
using namespace std;

void print(int n){
    if(n==2){
    cout<<2<<endl;
    return;
    }
    cout<<n<<endl;
    print(n-2);
}

int main()
{
    int n = 10;
    print(n);
}