
//T.C = O(2^N)
//S.C = O(N)

#include<bits/stdc++.h>
using namespace std;

bool find(int arr[], int index, int n, int target) {
    // Base Case 1: Target achieved!
    if (target == 0) return true;

    // Base Case 2: Out of bounds or target exceeded
    if (index == n || target < 0) return false;

    // IMPORTANT: You must return the result of the logical OR
    return find(arr, index + 1, n, target) || find(arr, index + 1, n, target - arr[index]);
}

int main() {
    int arr[] = {3, 6, 4, 5};
    int n = 4;
    int target = 12; // 3 + 4 + 5 = 12, so this should return 1 (true)
    
    if (find(arr, 0, n, target)) {
        cout << "Target found! Result: 1" << endl;
    } else {
        cout << "Target not possible. Result: 0" << endl;
    }
}