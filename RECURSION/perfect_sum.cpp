
// T.C = O(2^N)
//S.C = 0(N)

#include<bits/stdc++.h>
using namespace std;

int perfect(int arr[], int index, int n, int sum) {
    // Base Case: If we've considered all elements
    if(index == n) {
        // If the remaining sum is 0, we found 1 valid subset
        return (sum == 0) ? 1 : 0;
    }

    // Recursive Step: Return the total count from both branches
    // Branch 1: Exclude the element + Branch 2: Include the element
    return perfect(arr, index + 1, n, sum) + perfect(arr, index + 1, n, sum - arr[index]);
}

int main() {
    int arr[] = {2, 5, 6, 1};
    int n = 4;
    int sum = 8; // (2+5+1 = 8) and (2+6 = 8) -> Should return 2
    
    cout << "Number of subsets with sum " << sum << " : " << perfect(arr, 0, n, sum);
    
    return 0;
}