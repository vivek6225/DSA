#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int value){
        data = value;
        next = NULL;

    }
};
Node*CreateLinkedList(int arr[], int index, int size)
{
    //BASE CASE
    if(index == size)
    
    return NULL;

    //create node

    Node*temp;
    temp = new Node(arr[index]);
    temp->next = CreateLinkedList(arr,index+1,size);
    return temp;
    }


int main()
{
    Node*Head;
    Head = NULL;
    int arr[] = {19,4,6,8,10};
    
    Head = CreateLinkedList(arr,0,5);

    //DELETE END NODE

     if(Head!=NULL)
    {
        //only one head is present

        if(Head->next == NULL)
        {

        Node*temp = Head;
        delete temp;
        Head = NULL;
        }
    
        // more than 1 node is present 

        else{
            
            Node*curr = Head;
            Node*prev = NULL;
        
        
        // curr->next is not null

        while(curr->next!= NULL)
        {
            prev = curr;
            curr = curr->next;
        }
         
        prev->next = curr->next;
        delete curr;
        
        }  
}
 
          
          //print

          
     Node*temp;
        temp = Head;
        while(Head)
        {
            cout<<Head->data<<" ";
            Head = Head->next;
        }
    
}

    // print


    //  Node*temp;
    // temp = Head;
    // while(temp)
    // {
    //  cout<<temp->data;
    // Head = temp->next;
    // }
    // }

    


