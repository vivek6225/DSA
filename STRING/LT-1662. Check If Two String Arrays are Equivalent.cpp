//-----optimal Approach-------------------------
// T.C. → O(N)
// S.C. → O(1)
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    
        int i = 0; // String index in word1
        int j = 0; // Character index inside word1[i]

        int k = 0; // String index in word2
        int l = 0; // Character index inside word2[k]

        // Continue while both arrays have strings left
        while (i < word1.size() && k < word2.size()) {

            // If current characters are different, arrays are not equal
            if (word1[i][j] != word2[k][l]) {
                return false;
            }

            // Move to the next character
            j++;
            l++;

            // If current string of word1 is finished
            if (j == word1[i].size()) {
                j = 0; // Start from first character
                i++;   // Move to next string
            }

            // If current string of word2 is finished
            if (l == word2[k].size()) {
                l = 0; // Start from first character
                k++;   // Move to next string
            }
        }

        // Both arrays must be completely traversed
        if (i == word1.size() && k == word2.size()) {
            return true;
        } else {
            return false;
        }
    }
};


//-----Brute Force Approach-------------------------
// T.C. → O(N)
// S.C. → O(N)
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {

        string s1 = "";
        string s2 = "";

        // Combine all strings of word1
        for (int i = 0; i < word1.size(); i++) {
            s1 += word1[i];
        }

        // Combine all strings of word2
        for (int j = 0; j < word2.size(); j++) {
            s2 += word2[j];
        }

        // Compare the two complete strings
        return s1 == s2;
    }
};