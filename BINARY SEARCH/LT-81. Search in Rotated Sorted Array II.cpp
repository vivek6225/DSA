//-------Brute Force Approach-----------------
// Average Time Complexity: O(log n)
// Worst Time Complexity: O(n)   // Due to duplicates
// Space Complexity: O(1)

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0, end = n - 1;

        // Apply Binary Search
        while (start <= end) {
            int mid = start + (end - start) / 2;

            // Target found
            if (nums[mid] == target) {
                return true;
            }

            // If duplicates exist, shrink the search space
            if (nums[start] == nums[mid] && nums[mid] == nums[end]) {
                start++;
                end--;
                continue;
            }

            // Left half is sorted
            if (nums[start] <= nums[mid]) {

                // Target lies in the left sorted half
                if (nums[start] <= target && target < nums[mid]) {
                    end = mid - 1;
                }
                // Search in the right half
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
                // Search in the left half
                else {
                    end = mid - 1;
                }
            }
        }

        // Target not found
        return false;
    }
};
//-------Brute Force Approach-----------------
// Time Complexity = O(n)
// Space Complexity = O(1)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();

        // Traverse the entire array
        for (int i = 0; i < n; i++) {

            // If target is found, return true
            if (nums[i] == target) {
                return true;
            }
        }

        // Target not found
        return false;
    }
};