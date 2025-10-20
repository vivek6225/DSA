// #include<bits/stdc++.h>
// using namespace std;
// void fun0(int n){
//     cout<<"Happy birthday\n";
   
// }
// void fun1(int n){
//     cout<<n<<" days left for birthday\n";
//     fun0(0);
// }
// void fun2(int n){
//     cout<<n<<" days left for birthday\n";
//     fun1(n-1);
// }
// void fun3(int n){
//     cout<<n<<" days left for birthday\n";
//     fun2(n-1);
// }

// int main()
// {
//     int n = 3;
//     fun3(3);
// }

#include<bits/stdc++.h>
using namespace std;

void fun3(int n){
    if(n==0)
    {
    cout<< "happy birthday\n";
    return;
    }

    cout<<n<< " days left for birthday\n";
    fun3(n-1);
}
int main()
{
    int n  = 3;
    // fun3(3);
    fun3(8);
}

