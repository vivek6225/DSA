#include<bits/stdc++.h>
using namespace std;
 int factorial(int n){
  int fact = 1;
  for(int i = 1; i<=n; i++){
    fact = fact*i;
  }
  return fact;
}
int main(){
  cout<<"factorial 4 = "<<factorial(4)<<endl;
  cout<<"factorial 10 = "<<factorial(10);
  return 0;

}
