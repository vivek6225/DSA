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
  return (rear+1)%size==front;
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
  rear = (rear+1)%size;
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
    front = (front+1)%size;
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
   q.push(64);
   q.push(74);
   q.pop();
  q.push(2);
    q.push(4);
  q.pop();
   q.pop();

}