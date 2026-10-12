// Time:(O(n)), because counting takes (O(n)) and sorting 26 elements takes constant time.

// Auxiliary space: (O(1)), because we use two fixed-size arrays of 26 elements

class Solution {
public:
    bool closeStrings(string word1, string word2) {

        if (word1.size() != word2.size()) {
            return false;
        }

        int freq1[26] = {0};
        int freq2[26] = {0};

        // Count characters in both strings
        for (int i = 0; i < word1.size(); i++) {
            freq1[word1[i] - 'a']++;
        }

        for (int i = 0; i < word2.size(); i++) {
            freq2[word2[i] - 'a']++;
        }

        // Check that both strings contain the same characters
        for (int i = 0; i < 26; i++) {
            if ((freq1[i] == 0) != (freq2[i] == 0)) {
                return false;
            }
        }

        // Sort the frequency arrays
        sort(freq1, freq1 + 26);
        sort(freq2, freq2 + 26);

        // Compare the frequency distributions
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) {
                return false;
            }
        }

        return true;
    }
};