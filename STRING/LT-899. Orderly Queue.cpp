//------------- Optimal  Approach------------------

// 1. k == 1  → Try all rotations → take smallest
// 2. k > 1  → Sort the string

// k == 1 → O(n²) time, O(n) space 
// k > 1  → O(n log n) time, O(log n) space

// T.C. = O(n²)
// S.C. = O(n)

class Solution {
public:
    string orderlyQueue(string s, int k) {
        
        int n = s.size();

        // If k = 1, we can only rotate the string
        if (k == 1) {
            
            // Store the smallest rotation found so far
            string ans = s;

            // Try all possible rotations
            for (int i = 1; i < n; i++) {
                
                // Move first i characters to the end
                string rotated = s.substr(i) + s.substr(0, i);

                // Keep the lexicographically smaller string
                if (rotated < ans) {
                    ans = rotated;
                }
            }

            return ans;
        }

        // If k > 1, we can arrange characters in sorted order
        sort(s.begin(), s.end());

        return s;
    }
};
