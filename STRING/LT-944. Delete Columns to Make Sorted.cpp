// Time : O(n times k), where n is the number of strings and k is their length.
// Auxiliary space : O(1).

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();          // Number of strings (rows)
        int k = strs[0].length();     // Length of each string (columns)
        int count = 0;                // Number of columns to delete

        // Visit each column.
        for (int i = 0; i < k; i++) {

            // Compare each row with the row above it.
            for (int j = 1; j < n; j++) {

                // If the current character is smaller,
                // this column is not sorted.
                if (strs[j][i] < strs[j - 1][i]) {
                    count++;
                    break;  // Count this column only once.
                }
            }
        }

        return count;
    }
};
 