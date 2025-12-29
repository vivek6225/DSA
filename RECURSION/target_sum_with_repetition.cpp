
// No Repetition
// T.C = O(2^N)
// S.C = O(N)

//With Repetition
// T.C = Exponential   (≈ O(2^N))
 // S.C =O(target)


#include<bits/stdc++.h>
using namespace std;

int repetition(int arr[], int index, int n, int sum){

    // Base case: if sum becomes 0, we found one valid way
    if(sum == 0){
        return 1;
    }

    // If we run out of elements or sum becomes negative,
    // then this path is invalid
    if(index == n || sum < 0){
        return 0;
    }

    // Two choices:
    // Skip current element and move to next index
    //  Take current element and stay on same index (repetition allowed)
    return repetition(arr, index + 1, n, sum)     
         + repetition(arr, index,     n, sum - arr[index]); 
}

int main(){
    int arr[] = {2,3,4};
    int n = 3;
    int sum = 6;

    cout << "target sum with repetition " << sum << " : "
         << repetition(arr, 0, n, sum);
}
