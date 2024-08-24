#include<bits/stdc++.h>
using namespace std;
void printeven(int num,int N)
{
    if(num==N)
    {
        cout<<num<<endl;
        return;

    }
     printeven(num+2,N);
    cout<<num<<endl;
    // printeven(num+2,N);

}
int main()
{
    int N;
    cin>>N;
    if(N%2==1)
    N--;
    printeven(2,N);
}