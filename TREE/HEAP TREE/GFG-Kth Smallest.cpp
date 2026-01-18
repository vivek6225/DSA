
// ---------------------Optimal Approach-------------------------------------------
//T.C = O(n log k)
//S.C = O(k)
class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        
        int n = arr.size();
        
        // Max heap to store k smallest elements
        priority_queue<int> q;
        
        // Step 1: Push first k elements into the max heap
        for (int i = 0; i < k; i++) {
            q.push(arr[i]);
        }
        
        // Step 2: Traverse remaining elements
        for (int i = k; i < n; i++) {
            
            // If current element is smaller than the largest
            // element in heap, it should be included
            if (arr[i] < q.top()) {
                q.pop();          // remove the largest
                q.push(arr[i]);   // insert the smaller element
            }
        }
        
        // Step 3: Top of max heap is the kth smallest element
        return q.top();
    }
};

//----------------------------------------------------------------------------

//T.C = (n + k log n)
//S.C = (n)
class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {

        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> q;

        //   push all elements into min-heap
        for (int i = 0; i < n; i++) {
            q.push(arr[i]);
        }

        //   remove (k - 1) smallest elements
        for (int i = 1; i < k; i++) {
            q.pop();
        }

        // Top element is the kth smallest
        return q.top();
    }
};

//---------------------------------------------------------------------------------

//T.C = O(n log n)
//S.C = O(lon n)

class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        
        // Step 1: Sort the array in ascending order
        // After sorting, smallest elements come first
        sort(arr.begin(), arr.end());
        
        // Step 2: Since k is 1-based index,
        // kth smallest element will be at index (k - 1)
        return arr[k - 1];
    }
};
