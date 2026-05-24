//T.C = O(N)
//T.C = O(1)
class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();

        // Pointer at beginning and end
        int start = 0, end = n - 1;

        // Continue while both ends have same character
        while (start < end && s[start] == s[end]) {

            // Character present at both ends
            char ch = s[start];

            // Skip same characters from left side
            while (start < end && s[start] == ch) {
                start++;
            }

            // Skip same characters from right side
            while (end >= start && s[end] == ch) {
                end--;
            }
        }

        // Length of remaining valid substring
        return end - start + 1;
    }
};