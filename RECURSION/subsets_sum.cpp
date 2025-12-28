
//T.C = O(2^N)
//S.C = O(N)

#include<bits/stdc++.h>
using namespace std;

void print(int arr[], int index, int n, vector<int>& temp) {

    // Base Case: one complete subset
    if(index == n) {
        int sum = 0;
        for(int x : temp) sum += x;

        // print subset
        cout << "{ ";
        for(int x : temp) cout << x << " ";
        cout << "}  -> Sum = " << sum << endl;
        return;
    }

    //  Exclude current element
    print(arr, index + 1, n, temp);

    //  Include current element
    temp.push_back(arr[index]);
    print(arr, index + 1, n, temp);
    temp.pop_back();   // backtrack
}

int main() {
    int arr[] = {1, 2, 3, 4};
    vector<int> temp;

    int n = sizeof(arr) / sizeof(arr[0]);

    print(arr, 0, n, temp);
}
