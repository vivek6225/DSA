
#include<iostream>
using namespace std;
void lowerToUpper(string &str,int index){

  if(index == -1)
  return;
  
    if(str[index] >= 'a' && str[index] <= 'z')
  str[index] = 'A' + str[index]- 'a';
  return lowerToUpper(str,index-1);
}
int main(){
  string str = "vivek";
  lowerToUpper(str,str.length()-1);
  cout<<str;
}