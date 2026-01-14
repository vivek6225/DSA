#include<bits/stdc++.h>
using namespace std;

// Function to display all elements of queue
void display(queue<int> q){
    // Pass by value so original queue is not modified
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();   // remove front after printing
    }
    cout << endl;
}

int main(){

    int arr[] = {1,2,3,4,5,6,7};
    int n = 7;
    int k = 4;

    queue<int> q;

    // Step 1: push first (k-1) elements into queue
    // Queue now contains: 1 2 3
    for(int i = 0; i < k-1; i++)
        q.push(arr[i]);

    // Step 2: from index k-1 onward, push new element,
    // print the queue, then remove front (sliding window)
    for(int i = k-1; i < n; i++){
        q.push(arr[i]);   // add current element
        display(q);      // print current window of size k
        q.pop();         // remove front to slide window
    }

    return 0;
}
