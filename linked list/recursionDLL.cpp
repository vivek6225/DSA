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

    Node*trav = head;
    while(trav)
    {
        cout<<trav->data<<" ";
        trav = trav->next;
    }

}

