 //------------- brute Force Approach------------------
 
// T.C. → O(n²)
// S.C. → O(1) auxiliary space

class Solution {
public:
    string makeGood(string s) {

        int i = 0;

        // Continue while i and i+1 are valid positions
        while (i + 1 < s.size()) {

            // Check if characters are the same letter but different case
            if (tolower(s[i]) == tolower(s[i + 1]) &&
                s[i] != s[i + 1]) {

                // Remove both characters
                s.erase(i, 2);

                // Check the previous pair again
                if (i > 0) {
                    i--;
                }
            }
            else {
                // Pair is good, move to the next pair
                i++;
            }
        }

        return s;
    }
};


