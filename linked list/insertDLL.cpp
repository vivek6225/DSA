#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node*next;
    Node*prev;
    Node(int value)  //constructor
    {
    data = value;
    next = NULL;
    prev = NULL;
    }
};
int main()
{
    //insert a start
    Node *head = NULL;

    //Linkedlist doesn't exit

    if(head==NULL)
    head = new Node(9);

    //Already exist
  else{
   Node *temp = new Node(9);
   temp->next = head;
   head->prev = temp;
   head = temp;
  }

  // print

   Node *trav = head;
   while(trav)
   {
    cout<<trav->data<<" ";
    trav = trav->next;
   }

}