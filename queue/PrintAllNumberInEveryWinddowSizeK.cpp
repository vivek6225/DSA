#include<bits/stdc++.h>
using namespace std;
void display(queue<int>q){
  while(!q.empty()){
  cout<<q.front()<<" ";
  q.pop();
}
cout<<endl;
}
int main(){
 int arr[] = {1,2,3,4,5,6,7};
  int n = 7;
  int k = 4;
  queue<int>q;
  // k element ko push kar queue ka andar
  for(int  i = 0; i < k-1; i++)
    q.push(arr[i]);
    for(int  i = k-1; i < n; i++ ){
      q.push(arr[i]);
      display(q);
      q.pop();
     
    }
    return 0;
}