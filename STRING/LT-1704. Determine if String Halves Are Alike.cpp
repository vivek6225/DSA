// T.C. → O(n)
// S.C. → O(1)

class Solution {
public:

    // Check whether the character is a vowel
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' ||
                ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' ||
                ch == 'O' || ch == 'U');
    }

    bool halvesAreAlike(string s) {

        int n = s.size();

        // Find the starting index of the second half
        int mid = s.size() / 2;

        // i points to the first half
        int i = 0;

        // j points to the second half
        int j = mid;

        int count1 = 0; // Vowels in first half
        int count2 = 0; // Vowels in second half

        // Traverse both halves at the same time
        while (i < mid && j < n) {

            // Count vowel in first half
            if (isVowel(s[i])) {
                count1++;
            }

            // Count vowel in second half
            if (isVowel(s[j])) {
                count2++;
            }

            // Move both pointers forward
            i++;
            j++;
        }

        // Both halves are alike if vowel counts are equal
        return count1 == count2;
    }
};