#include<bits/stdc++.h>
using namespace std;
int main(){
  queue<int>q;
  q.push(2);
  q.push(22);
  q.push(12);
  q.push(1);
  q.push(121);
  //delete
  q.pop();
  
  cout<<"front = "<<q.front()<<endl;
  cout<<"back = "<<q.back()<<endl;
  cout<<"queue is empty = "<<q.empty()<<endl;

  cout<<"size of queue = "<<q.size()<<endl;

  //Display enire queue
  cout<<"queue elements = ";
  queue<int>temp = q ; // make a copy so original queue is not affected
  while(!temp.empty()){
    cout<<temp.front()<<" ";
    temp.pop();

  }
  cout<<endl;

}