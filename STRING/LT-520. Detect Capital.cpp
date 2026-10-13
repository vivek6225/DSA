
class Solution {
public:
    // Check whether all characters are uppercase (A-Z).
    bool AllCap(string word) {
        for (char &ch : word) {

            // If any character is not uppercase, return false.
            if (ch < 'A' || ch > 'Z') {
                return false;
            }
        }

        // All characters are uppercase.
        return true;
    }

    // Check whether all characters are lowercase (a-z).
    bool AllSm(string word) {
        for (char ch : word) {

            // If any character is not lowercase, return false.
            if (ch < 'a' || ch > 'z') {
                return false;
            }
        }

        // All characters are lowercase.
        return true;
    }

    bool detectCapitalUse(string word) {

        // Case 1: All letters are uppercase, e.g., "USA".
        // Case 2: All letters are lowercase, e.g., "leetcode".
        // Case 3: First letter is uppercase and the rest are
        // lowercase, e.g., "Google".
        if (AllCap(word) || AllSm(word) ||
            ((word[0] >= 'A' && word[0] <= 'Z') &&
             AllSm(word.substr(1)))) {
            return true;
        }

        // None of the valid capitalization patterns matched.
        return false;
    }
};
