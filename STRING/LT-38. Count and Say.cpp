
// T.C. → O(n × L) 
// S.C. → O(L)

class Solution {
public:
    string countAndSay(int n) {

        // Base case: first term is "1"
        if (n == 1) {
            return "1";
        }

        // Start with the first term
        string s = "1";

        // Generate the next term n-1 times
        for (int round = 1; round < n; round++) {

            // Store the newly generated term
            string result = "";

            // Read the current string
            for (int i = 0; i < s.size(); ) {

                // Current character we want to count
                char ch = s[i];

                // Count consecutive occurrences
                int count = 0;

                // Count same consecutive characters
                while (i < s.size() && ch == s[i]) {
                    count++;
                    i++;
                }

                // Add count first, then the character
                // Example: "111" -> "31"
                result += to_string(count);
                result += ch;
            }

            // The new result becomes the input for the next round
            s = result;
        }

        // Return the nth term
        return s;
    }
};



