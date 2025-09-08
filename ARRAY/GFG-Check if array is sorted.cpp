

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
  public:
    bool isSorted(vector<int>& arr) {
        int n = arr.size();
        
        // Start from 1 since we compare with previous element
        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[i - 1]) {
                return false;  // Not sorted
            }
        }
        return true;  // Sorted
    }
};
