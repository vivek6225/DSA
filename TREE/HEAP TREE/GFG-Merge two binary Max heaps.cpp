
//----------------Optimal Approach----------------------------------
// T.C= O(n + m)
// S.C= O(n + m)
class Solution {
  public:

    // Heapify function to maintain max-heap property at given index
    void Heapify(vector<int>& ans, int index, int n) {
        int largest = index;
        int left  = 2 * index + 1;
        int right = 2 * index + 2;

        // If left child is larger than root
        if (left < n && ans[left] > ans[largest])
            largest = left;

        // If right child is larger than largest so far
        if (right < n && ans[right] > ans[largest])
            largest = right;

        // If largest is not root, swap and continue heapifying
        if (largest != index) {
            swap(ans[largest], ans[index]);
            Heapify(ans, largest, n);
        }
    }

    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {

        vector<int> ans;

        // Step 1: Copy all elements of heap a
        for (int i = 0; i < n; i++) {
            ans.push_back(a[i]);
        }

        // Step 2: Copy all elements of heap b
        for (int i = 0; i < m; i++) {
            ans.push_back(b[i]);
        }

        // Step 3: Build max heap from merged array
        int size = ans.size();
        for (int i = size / 2 - 1; i >= 0; i--) {
            Heapify(ans, i, size);
        }

        return ans;
    }
};

//--------------------------Brute force Approach----------------------------------------
//T.C = O((n + m) log (n + m))
//S.C = O(n + m)

class Solution {
  public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {

        // Max heap to store all elements from both heaps
        priority_queue<int> p;

        // Push all elements of heap a into max heap
        for(int i = 0; i < n; i++){
            p.push(a[i]);
        }

        // Push all elements of heap b into max heap
        for(int i = 0; i < m; i++){
            p.push(b[i]);
        }

        // Vector to store the merged max heap
        vector<int> newHeap;

        // Extract elements from max heap and store in vector
        while(!p.empty()){
            newHeap.push_back(p.top());  // always get the maximum element
            p.pop();
        }

        return newHeap;
    }
};
