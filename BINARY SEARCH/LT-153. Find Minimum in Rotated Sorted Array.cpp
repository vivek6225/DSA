//-----------------Optimal Approach-----------------
// Time Complexity = O(log n) (Binary Search)
// Space Complexity = O(1)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = n - 1;

        // Perform Binary Search until only one element remains
        while (start < end) {
            int mid = start + (end - start) / 2;

            // If middle element is greater than the last element,
            // the minimum lies in the right half.
            if (nums[mid] > nums[end]) {
                start = mid + 1;
            }
            // Otherwise, the minimum is at mid or in the left half.
            else {
                end = mid;
            }
        }

        // start (or end) points to the minimum element.
        return nums[start];
    }
};

//---------Brute Force Approach--------------------------
// Time Complexity = O(n) 
// Space Complexity = O(1)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < mini) {
                mini = nums[i];
            }
        }

        return mini;
    }
};