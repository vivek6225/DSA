#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
    Node *prev;
   Node(int value)
   {
    data = value;
    next = NULL;
    prev = NULL;
    
   }
};
int main ()
{
    Node *head = NULL;

    //linkedlist does not exit
    if(head==NULL)
    {
        head = new Node(6);
    }

    //exist karta h

    else{

        //last node pr pauchana h

        Node *curr = head;
        while(curr->next)
        {
            curr = curr->next;

        };
        Node *temp = new Node(6);
        curr->next = temp;
        temp->prev = curr;
    }
    Node *trav = head;
    while(trav)
    {
    cout<<trav->data<<" ";
    trav = trav->next;
    }

}