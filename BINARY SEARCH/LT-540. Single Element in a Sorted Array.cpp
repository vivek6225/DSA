// --------------Brute Force Approach----------------
// Time Complexity = O(n)
// Space Complexity = O(1)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        // XOR all elements
        // Duplicate elements cancel each other (a ^ a = 0)
        // The unique element remains (0 ^ x = x)
        for (int i = 0; i < n; i++) {
            ans ^= nums[i];
        }

        // Return the single non-duplicate element
        return ans;
      }
    };
        //-------------or------------
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        // If there is only one element or the first element is unique
        if (n == 1 || nums[0] != nums[1]) {
            return nums[0];
        }

        // Check middle elements
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1]) {
                return nums[i];
            }
        }

        // Otherwise, the last element is unique
        return nums[n - 1];
    }
};

//---------- Optimal Approach---------------------------
// Time Complexity : O(log n)
// Space Complexity: O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        // If there is only one element, it is the answer
        if (n == 1)
            return nums[0];

        int start = 0, end = n - 1;

        // Apply Binary Search
        while (start <= end) {
            int mid = start + (end - start) / 2;

            // Check if the first element is the single element
            if (mid == 0 && nums[0] != nums[1])
                return nums[0];

            // Check if the last element is the single element
            if (mid == n - 1 && nums[n - 1] != nums[n - 2])
                return nums[n - 1];

            // If the current element is different from both neighbours,
            // then it is the single non-duplicate element
            if (nums[mid - 1] != nums[mid] &&
                nums[mid] != nums[mid + 1])
                return nums[mid];

            // If mid is at an even index
            if (mid % 2 == 0) {

                // Current element forms a pair with the left neighbour,
                // so the single element lies in the left half
                if (nums[mid - 1] == nums[mid]) {
                    end = mid - 2;
                }

                // Current element forms a pair with the right neighbour,
                // so the single element lies in the right half
                else {
                    start = mid + 2;
                }
            }

            // If mid is at an odd index
            else {

                // Current element forms a pair with the left neighbour,
                // so the single element lies in the right half
                if (nums[mid - 1] == nums[mid]) {
                    start = mid + 1;
                }

                // Current element forms a pair with the right neighbour,
                // so the single element lies in the left half
                else {
                    end = mid - 1;
                }
            }
        }

        // This line will never execute for a valid input
        return -1;
    }
};
//--------OR-----------------------
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            // Make sure mid is even
            if (mid % 2 == 1) {
                mid--;
            }

            // Pair is valid, so the single element is on the right
            if (nums[mid] == nums[mid + 1]) {
                start = mid + 2;
            }
            // Pair is broken, so the single element is on the left (or at mid)
            else {
                end = mid;
            }
        }

        // start (or end) points to the single element
        return nums[start];
    }
};