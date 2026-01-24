//--------------OptimaApproach------------------------------------
//T.C =0(n log k)
//S.C =0( k)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        // Min-heap of size k
        // It will store the k largest elements seen so far
        priority_queue<int, vector<int>, greater<int>> p;

        // Step 1: Push first k elements into the min-heap
        for (int i = 0; i < k; i++) {
            p.push(nums[i]);
        }

        // Step 2: Process remaining elements
        for (int i = k; i < nums.size(); i++) {

            // If current element is larger than the smallest in heap
            if (nums[i] > p.top()) {
                p.pop();          // remove smallest among k largest
                p.push(nums[i]);  // insert current element
            }
        }

        // Step 3: Top of min-heap is the kth largest element
        return p.top();
    }
};
//----------------------------------------------------------------------
//T.C = O(n log n)
//S.C = O(n )
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        int n = nums.size();
        priority_queue<int> p;

        // push all elements into max heap
        for (int i = 0; i < n; i++)
            p.push(nums[i]);

        // remove (k-1) largest elements
        for (int i = 1; i < k; i++) {
            p.pop();
        }

        // kth largest element
        return p.top();
    }
};
//---------------------------------------------------------------------------
//T.C = O(n log n)
//T.C = O(1)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        // Step 1: Sort the array in ascending order
        sort(nums.begin(), nums.end());

        // Step 2: Get the size of the array
        int n = nums.size();

        // Step 3: The kth largest element will be at index (n - k)
        // because the largest element is at index (n - 1)
        return nums[n - k];
    }
};
