#include<bits/stdc++.h>
using namespace std;
void printodd(int num, int N)
{
    if(num==N)
    {
    cout<<num<<endl;
    return;
    }
    cout<<num<<endl;
    printodd(num+2,N);

}
int main()
{
    int N;
    cin>>N;
    if(N%2==1)
    N++;
    printodd(1,N);
}