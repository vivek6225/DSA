
  // s.c = 0(logn)
  // t.c = 0(logn)
 

  class Solution {
public:
    // Recursive function to perform binary search
    int binarySearch(vector<int>& arr, int tar, int start, int end) {

        // Base condition: if search range becomes invalid, element not found
        if (start <= end) {
            
            // Step 1: Find the middle index (to avoid overflow)
            int mid = start + (end - start) / 2;

            // Step 2: Check if middle element is equal to the target
            if (arr[mid] == tar)
                return mid;  // Target found at index mid

            // Step 3: If middle element is smaller than target,
            // search the right half of the array
            else if (arr[mid] < tar)
                return binarySearch(arr, tar, mid + 1, end);

            // Step 4: If middle element is larger than target,
            // search the left half of the array
            else
                return binarySearch(arr, tar, start, mid - 1);
        }

        // Step 5: If target not found in the array, return -1
        return -1;
    }

    // Main function that starts the recursive search
    int search(vector<int>& arr, int tar) {
        // Call binarySearch on full array range (0 to n-1)
        return binarySearch(arr, tar, 0, arr.size() - 1);
    }
};
