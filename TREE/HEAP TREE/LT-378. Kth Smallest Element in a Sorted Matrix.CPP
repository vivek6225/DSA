
//T.C = O(n log range)
//S.C = O(1)
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];

        // Binary search on the value range
        while (low < high) {
            int mid = low + (high - low) / 2;

            // Count how many numbers <= mid
            int count = 0;
            int row = n - 1, col = 0;

            while (row >= 0 && col < n) {
                if (matrix[row][col] <= mid) {
                    count += (row + 1);  // all elements above are <= mid
                    col++;
                } else {
                    row--;
                }
            }

            if (count < k) {
                low = mid + 1;   // kth smallest is bigger
            } else {
                high = mid;      // kth smallest is mid or smaller
            }
        }

        return low;
    }
};
//----------------------------Brute Force Approach-----------------------
//TC = O(n² log n)
// SC = O(n²)

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        vector<int> arr;
        int n = matrix.size();

        // Flatten matrix into 1D array
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr.push_back(matrix[i][j]);   
            }
        }

        // Sort the 1D array
        sort(arr.begin(), arr.end());

        // kth smallest (1-based index)
        return arr[k - 1];
    }
};
