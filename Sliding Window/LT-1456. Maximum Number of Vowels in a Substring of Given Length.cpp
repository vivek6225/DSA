//----------------optimal approach------------
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    // Check if a character is a vowel
    bool isVowels(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' ||
                ch == 'o' || ch == 'u');
    }

    int maxVowels(string s, int k) {
        int maxV = 0;   // Stores maximum vowels found
        int count = 0;  // Vowels in current window

        int n = s.size();
        int i = 0, j = 0;

        while (j < n) {

            // Add current character to window
            if (isVowels(s[j])) {
                count++;
            }

            // When window size becomes k
            if (j - i + 1 == k) {

                // Update answer
                maxV = max(maxV, count);

                // Remove leftmost character before sliding
                if (isVowels(s[i])) {
                    count--;
                }

                i++; // Slide window
            }

            j++;
        }

        return maxV;
    }
};

//----------------Brute Force approach------------
//  Time Complexity: O(n*k)
// Space Complexity: O(1)
class Solution {
public:
    // Check whether a character is a vowel
    bool isVowels(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' ||
                ch == 'o' || ch == 'u');
    }

    int maxVowels(string s, int k) {
        int n = s.size();
        int ans = 0; // Stores maximum vowels found

        // Generate all substrings/windows of size k
        for (int i = 0; i <= n - k; i++) {

            int count = 0; // Vowel count for current window

            // Count vowels in the current window [i, i+k-1]
            for (int j = i; j < i + k; j++) {
                if (isVowels(s[j])) {
                    count++;
                }
            }

            // Update answer with maximum vowel count seen so far
            ans = max(ans, count);
        }

        return ans;
    }
};