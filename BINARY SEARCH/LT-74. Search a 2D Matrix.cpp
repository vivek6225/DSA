//------Optimal approach -----------------------------

// Time Complexity = O(log(m × n))
// Space Complexity = O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int start = 0, end = m * n - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            // Convert 1D index to 2D index
            int row = mid / n;
            int col = mid % n;

            if (matrix[row][col] < target) {
                start = mid + 1;
            }
            else if (matrix[row][col] > target) {
                end = mid - 1;
            }
            else {
                return true;
            }
        }

        return false;
    }
};

//------brute force approach --------------------
// Time Complexity = O(rows + cols)
// Space Complexity = O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // Traverse each row
        for (int i = 0; i < matrix.size(); i++) {

            // Traverse each column
            for (int j = 0; j < matrix[0].size(); j++) {

                // If target is found, return true
                if (matrix[i][j] == target) {
                    return true;
                }
            }
        }

        // Target not found
        return false;
    }
};