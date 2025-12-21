
#include<iostream>
using namespace std;

void reverse(string &str,int start,int end){

  if(start >= end)
  return ;
  char c = str[start];
  str[start] = str[end];
  str[end] = c;

  
  return reverse(str,start+1,end-1);
  
}
int main(){
  string str = "vivek";
  reverse(str,0,str.length()-1);
  cout<<str;
}