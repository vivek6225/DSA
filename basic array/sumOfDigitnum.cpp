#include<bits/stdc++.h>
using namespace std;
int sumOfdigit(int num){
int digitsum = 0;
while(num>0){
  int lastdigit= num%10;
  num /=10;
  digitsum += lastdigit;
}
  return digitsum;
}

int main(){
  cout<<sumOfdigit(1457);
  return 0;

}
