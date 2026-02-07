//--------------------Optimal Approah----------------------------------------

// T.C: O(N log K2)
// S.C: O(K2)

class Solution {
  public:
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {

        // Max heap to keep track of K1 smallest elements
        priority_queue<long long> p1;

        // Max heap to keep track of (K2 - 1) smallest elements
        priority_queue<long long> p2;

        // Step 1: Push first K1 elements into heap p1
        for(long long i = 0; i < K1; i++){
            p1.push(A[i]);
        }

        // Step 2: Push first (K2 - 1) elements into heap p2
        for(long long i = 0; i < K2 - 1; i++){
            p2.push(A[i]);
        }

        // Step 3: Process remaining elements to maintain K1 smallest elements in p1
        // If current element is smaller than the largest in p1,
        // replace the largest with current element
        for(long long i = K1; i < N; i++){
            if(A[i] < p1.top()){
                p1.pop();
                p1.push(A[i]);
            }
        }

        // Step 4: Process remaining elements to maintain (K2 - 1) smallest elements in p2
        for(long long i = K2 - 1; i < N; i++){
            if(A[i] < p2.top()){
                p2.pop();
                p2.push(A[i]);
            }
        }

        // Step 5: Calculate sum of K1 smallest elements
        long long sum1 = 0;
        while(!p1.empty()){
            sum1 += p1.top();
            p1.pop();
        }

        // Step 6: Calculate sum of (K2 - 1) smallest elements
        long long sum2 = 0;
        while(!p2.empty()){
            sum2 += p2.top();
            p2.pop();
        }

        // Step 7: Difference gives sum of elements strictly between K1-th and K2-th smallest
        return sum2 - sum1;
    }
};

//--------------------Brute Force Approah----------------------------------------
//T.C: O(N log N)
//S.C: O(1)   // or O(log N) auxiliary due to sort

class Solution {
  public:
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {

        // Step 1: Sort the array
        sort(A, A + N);

        long long sum = 0;

        // Step 2: Sum elements strictly between K1-th and K2-th smallest
        for (int i = K1; i < K2 - 1; i++) {
            sum += A[i];
        }

        return sum;
    }
};
