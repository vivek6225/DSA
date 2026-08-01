//------brute Force Approach-----------------
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        // Traverse the entire array
        for (int i = 0; i < n; i++) {

            // If target is found, return its index
            if (nums[i] == target) {
                return i;
            }
        }

        // Target not found
        return -1;
    }
};
////--------------Optimal Approach-----------------
// Time Complexity: O(log n)
// Space Complexity: O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0, end = n - 1;

        // Apply Binary Search
        while (start <= end) {
            int mid = start + (end - start) / 2;

            // Target found
            if (nums[mid] == target) {
                return mid;
            }

            // Left half is sorted
            if (nums[start] <= nums[mid]) {

                // Target lies in the left sorted half
                if (nums[start] <= target && target < nums[mid]) {
                    end = mid - 1;
                }
                // Otherwise, search in the right half
                else {
                    start = mid + 1;
                }
            }

            // Right half is sorted
            else {

                // Target lies in the right sorted half
                if (nums[mid] < target && target <= nums[end]) {
                    start = mid + 1;
                }
                // Otherwise, search in the left half
                else {
                    end = mid - 1;
                }
            }
        }

        // Target not found
        return -1;
    }
};