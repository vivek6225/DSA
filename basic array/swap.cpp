#include<iostream>
using namespace std;
void printArray(int arr[],int n)
{
    for(int  i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
}

void swapalternate (int arr[],int size){
    for(int i=0;i<size;i=i+2)
    {
        if(arr[i+1]<arr[i])
        {
            swap(arr[i+1],arr[i]);
        }
    }

}

int main(){
    int even[8]={ 5,2,9,4,7,6,1,0};
    int odd[6]={11,33,9,70,43 };


swapalternate(even,8);
printArray(even,8);
cout<<endl;
swapalternate(odd,6);
printArray(odd,6);
}