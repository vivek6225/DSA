#include<bits/stdc++.h>
using namespace std;
class Node
{
  public:
  int data;
  Node*next;
  Node(int value)
  {
    data = value;
    next =  NULL;
  }

};
class Queue
{
  Node*front ;
  Node*rear;
  public:
 
  Queue()
  {
     front=rear=NULL;
  }
  //queue is empty
  bool IsEmpty()
  {
    return front==NULL;
  }
  //push element into queue
  void push(int x)
  {
    //empty
    cout<<" pushed "<<x<<"into the queue\n";
   if(IsEmpty())
    {
    front = rear = new Node(x);

    }
    // empty na ho

    else{
      rear->next = new Node(x);
      if(rear==NULL)
      {
        cout<<"queue overflow\n";
        return;
      }
         cout<<" pushed "<<x<<" into the queue\n ";
      rear = rear->next;
    }
  }
 
    void pop()
       // empty to nahi h
    {
      
       if(IsEmpty())
       {
        cout<<"queue is underflow";
        return;
       }
       else{
           //cout<<" poped "<<front->data<<" from the queue\n ";
           Node*temp =  front;
           front = front->next;
           delete temp;
       }
    }
  int start()
  {
  if(IsEmpty())
  {
    cout<<"queue is empty\n";
    return -1;

  }
 else
 {
  return front->data;
 }
}
};
int main()
{
Queue q;
q.push(23);
q.push(25);
q.push(26);
q.push(20);
}