#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[100];
    int key,flag=0,n,i;
    cout<<"enter the size of element = ";
    cin>>n;
    cout<<"enter the element = ";
   for(i = 0; i<n; i++){
    cin>>arr[i];
   }
    cout<<"enter the element to the search = ";
    cin>>key;

    for( i = 0; i<n; i++){
        if(arr[i]==key){
          flag++;
          break;
        }
       
    } 
    if(flag==1)
        cout<<"element found"<<endl;
    
        else{
            cout<<"element not found";
        }
    
    return 0;
}

