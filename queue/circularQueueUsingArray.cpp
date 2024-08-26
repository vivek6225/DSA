#include<bits/stdc++.h>
using namespace std;
// implement queue using array
class Queue {
  int *arr;
  int front,rear,size;
  public:

  // create constructor
   Queue(int n)
  {
    arr = new int(n);
    size = n;
    front=rear=-1;
  }
  
  //queue is empty or not
  bool IsEmpty()
  {
    return front==-1;
  }
  //queue is full or not
  bool IsFull()
  {
  return rear == size-1;
  }
  // push element into queue,  end
  void push(int x)
  {
// empty
  if(IsEmpty())
  {
    cout<<" pushed "<<x<< " into the queue\n ";
    front=rear=0;
    arr[0];
    return;
  }
  //FULL
 else if(IsFull())
 {
  cout<<"queue is overflow\n";
  return;
 }
   //INSERT
 else{
  cout<<" pushed "<<x<<" into the queue\n ";
  rear = rear+1;
  arr[rear]=x;
 }
  }
  
  //pop element ,starting
  void pop()
  {
    //EMPTY
    if(IsEmpty())
    {
      cout<<"queue underflow\n";
      return;
    }
    //pop kar do
    else{

    if(front==rear)
    {
      cout<<" poped "<<arr[front]<<" into the queue\n ";
       front=rear=-1;
  }
  else{
    front = front+1;
      cout<<" poped "<<arr[front]<<" into the queue\n ";
  }
    }
  }
  //start ma kaun sa element rakha h
  int start(){
    if(IsEmpty())
    {
      cout<<"queue is empty\n";
      return -1;
    }
    else
    return arr[front];
  }
};
 
int main()
{
  Queue q(5);
  q.push(7);
  q.push(54);
  q.push(2);
  q.pop();
  q.pop();
   q.pop();

 int x = q.start();
 if(!q.IsEmpty())
 cout<<x<<" ";
}