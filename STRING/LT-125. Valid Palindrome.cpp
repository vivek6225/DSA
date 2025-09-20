
// T.C = 0(n)
// S.C = 0(1)

class Solution {
public:
    // Helper function: check if character is alphanumeric
    bool isAlphaNum(char ch) {
        // Check digit (0-9) or alphabet (a-z after converting to lowercase)
        if ((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')) {
            return true;
        }
        return false;
    }

    bool isPalindrome(string s) {
        int start = 0, end = s.length() - 1; // two pointers: start and end

        while (start < end) {
            // If start character is not alphanumeric, move forward
            if (!isAlphaNum(s[start])) {
                start++;
                continue;
            }

            // If end character is not alphanumeric, move backward
            if (!isAlphaNum(s[end])) {
                end--;
                continue;
            }

            // Compare lowercase versions of start and end
            if (tolower(s[start]) != tolower(s[end])) {
                return false; // mismatch → not a palindrome
            }

            // Move both pointers towards center
            start++;
            end--;
        }

        // If loop finishes → it's a palindrome
        return true;
    }
};