
#include<iostream>
using namespace std;

void print(int arr[], int index) {

    if (index == -1)      
        return;
       
       // print(arr,index-1);

         cout << arr[index] << " ";
         print(arr,index-1);
  
}

int main() {
    int arr[] = {1,2,3,4,5};
    print(arr,  4);
}
