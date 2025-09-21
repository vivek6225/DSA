
// T.C = 0(n)
//S.C =0(1)

class Solution {
public:
    int longestPalindrome(string s) {
        // Frequency arrays for lowercase (a-z) and uppercase (A-Z) letters
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);

        // Count frequency of each character in string
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'a')   // lowercase letter
                lower[s[i] - 'a']++;// 's[i] - 'a'' gives index (0 for 'a', 1 for 'b', ..., 25 for 'z')
            else               
                upper[s[i] - 'A']++; // uppercase letter
        }

        int count = 0;   // length of longest palindrome
        bool odd = 0;    // to check if any odd frequency character exists

        // Traverse lowercase and uppercase frequency arrays
        for (int i = 0; i < 26; i++) {
            // For lowercase letters
            if (lower[i] % 2 == 0)       
                count += lower[i];
            else {                       // odd frequency -> use all but 1
                count += lower[i] - 1;
                odd = 1;                 // mark that we found an odd count
            }

            // For uppercase letters
            if (upper[i] % 2 == 0)       // even frequency -> can use fully
                count += upper[i];
            else {                       // odd frequency -> use all but 1
                count += upper[i] - 1;
                odd = 1;                 // also mark odd found here
            }
        }

        // If there was at least one odd character,
        // we can place it in the middle of palindrome
        return count + odd;
    }
};