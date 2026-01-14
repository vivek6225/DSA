

// T.C = O(log N)
// S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
    int *arr;        // Array to store heap elements
    int size;        // Current number of elements in heap
    int total_size;  // Maximum capacity of heap

public:

    // Constructor → Initialize heap
    MaxHeap(int n){
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    // ---------------- INSERT OPERATION ----------------
    // Inserts a value while maintaining MaxHeap property
    void insert(int value){

        if(size == total_size){
            cout<<"MaxHeap overflow\n";
            return; 
        }

        // Step-1: Insert element at the end
        arr[size] = value;
        int index = size;
        size++;

        // Step-2: Heapify-Up (Bubble Up)
        while(index > 0 && arr[(index-1)/2] < arr[index]){
            swap(arr[index], arr[(index-1)/2]);
            index = (index-1)/2;
        }

        cout<<value<<" inserted into heap\n";
    }

    // ---------------- PRINT HEAP ----------------
    void print(){
        for(int i = 0; i < size; i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }

    // ---------------- HEAPIFY DOWN ----------------
    // Restores heap property from given index downward
    void Heapify(int index){
        int largest = index;
        int left = 2*index + 1;
        int right = 2*index + 2;

        if(left < size && arr[left] > arr[largest])
            largest = left;

        if(right < size && arr[right] > arr[largest])
            largest = right;

        if(largest != index){
            swap(arr[index], arr[largest]);
            Heapify(largest);
        }
    }

    // ---------------- DELETE OPERATION ----------------
    // Deletes maximum element (root)
    void Delete(){

        if(size == 0){
            cout<<"Heap underflow\n";
            return;
        }

        // Step-1: Element to be deleted is root
        cout<<arr[0]<<" deleted from heap\n";

        // Step-2: Move last element to root
        arr[0] = arr[size - 1];
        size--;

        // Step-3: Restore heap property
        Heapify(0);
    }
};

int main(){
    MaxHeap H1(6);

    H1.insert(4);
    H1.insert(14);
    H1.insert(11);
    H1.Delete();

    H1.insert(130);
    H1.insert(330);
    H1.Delete();

    H1.insert(430);
    H1.Delete(); 
    H1.Delete(); 
    H1.Delete();

    H1.print();
}
