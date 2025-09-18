#include<bits/stdc++.h>
using namespace std;
 int sumOfN(int n){
  int sum = 0;
  for(int i = 1; i<=n; i++){
  sum += i;
  }
  return sum;
  
    
}
int main(){
  cout<<"sum = "<<sumOfN(5);
  return 0;
  

}
