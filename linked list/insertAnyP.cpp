#include<bits/stdc++.h>
using namespace std;
class Node 
{
    public:
    int data;
    Node*next;
    Node*prev;
    Node(int value)
    {
        data = value;
        prev = NULL;
        next = NULL;
    }
};
    Node *CreateDLL(int arr[],int index,int size,Node*back)
    {
        if(index==size)
        return NULL;

        //Node create karo

        Node *temp = new Node(arr[index]);
        temp->prev = back;
       temp->next = CreateDLL(arr,index+1,size,temp);
       return temp;
    }

int main()
{
    Node *head = NULL;
    int arr[] = {1,2,3,4,5};
    head = CreateDLL(arr,0,5,NULL);

// insert at any point

    int pos = 2;
    //insert start
    if(pos==0)
    {
    if(head==NULL)
    {
        //linkedlist exist na kare
        Node*temp = new Node(9);
    }
    

    //exit karta h

    else{
        Node *temp = new Node(9);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    }
    else{
        Node *curr = head;

        //go to the node after which i have insert

        while(--pos)
        curr = curr->next;
    

    //insert at end

    if(curr->next==NULL)  //end
    {
    Node *temp = new Node(9);
    temp->prev = curr;
    curr->next = temp;
}
//insert at middle

else{
    Node *temp = new Node(9);
    temp->next = curr->next;
    temp->prev = curr;
    curr->next = temp;
   temp->next->prev = curr;
}
    }

    Node*trav = head;
    while(trav)
    {
        cout<<trav->data<<" ";
        trav = trav->next;
    }

}