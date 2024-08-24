#include<bits/stdc++.h>
using namespace std;
void print (int N){
    if(N==1)
    {
    cout<<1<<endl;
    return;
    }
    //  print(N-1);
    cout<<N<<endl;
      print(N-1);

}

int main(){
    int N;
    cin>>N;
    print(N);
}

