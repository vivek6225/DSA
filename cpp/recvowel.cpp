#include<bits/stdc++.h>
using namespace std;
int count(string str,int index)

{
 if(index==-1)
 return 0;
if(str[index]=='a'|| str[index]=='e'|| str[index]=='i'||str[index]=='o'||str[index]=='u')
 return 1+count(str,index-1);
return count(str,index-1);

}

int main()
{
    string str = "vivek";
    cout<<count(str,4);
}