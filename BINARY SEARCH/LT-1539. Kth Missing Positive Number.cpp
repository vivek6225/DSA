//---------Optimal Approch------------------------
// Time Complexity = O(log n)
// Space Complexity = O(1)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int start = 0;
        int end = arr.size() - 1;

        // Apply Binary Search
        while (start <= end) {

            int mid = start + (end - start) / 2;

            // Number of missing elements before arr[mid]
            int missing = arr[mid] - (mid + 1);

            // Missing numbers are less than k, search right half
            if (missing < k) {
                start = mid + 1;
            }
            // Search left half
            else {
                end = mid - 1;
            }
        }

        // Return the kth missing positive number
        return start + k;
    }
};
//---------Brute Force Approch-------------------------------
class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int n = nums.size();
        int num = 1;   // Current positive number
        int i = 0;     // Pointer for the array

        // Traverse until the array ends or k missing numbers are found
        while (i < n && k > 0) {

            // Current number exists in the array
            if (nums[i] == num) {
                i++;
            }
            // Current number is missing
            else {
                k--;
            }

            num++;
        }

        // If k is still remaining, continue after the array
        while (k--) {
            num++;
        }

        // num is incremented one extra time
        return num - 1;
    }
};