#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[],int n){
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void swapAlternate(int arr[],int size){
    for(int i = 0; i<size; i+=2){
        if( i+1 <size){ 
            swap(arr[i],arr[i+1]);
        }
    }

}
int main(){
    int even[8] = {4,5,6,1,9,0,1,99};
    int odd[5] = {7,8,9,0,1};

    swapAlternate(even,8);
    printArray(even,8);
    cout<<endl;

    swapAlternate(odd,5);
    printArray(odd,5);
    }

