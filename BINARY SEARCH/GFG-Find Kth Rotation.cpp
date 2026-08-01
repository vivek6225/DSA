//------------- Optimal Approach---------------
// Time Complexity = O(log n)
// Space Complexity = O(1)

class Solution {
public:
    int findKRotation(vector<int> &arr) {

        int n = arr.size();
        int start = 0, end = n - 1;

        // Apply Binary Search
        while (start < end) {
            int mid = start + (end - start) / 2;

            // Minimum lies in the left half (including mid)
            if (arr[mid] < arr[end]) {
                end = mid;
            }
            // Minimum lies in the right half
            else {
                start = mid + 1;
            }
        }

        // Index of the minimum element = number of rotations
        return start;
    }
};
//-------------Brute Force Approach-------------
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();

        // Find the index of the minimum element
        int minIndex = 0;

        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[minIndex]) {
                minIndex = i;
            }
        }

        return minIndex;
    }
};