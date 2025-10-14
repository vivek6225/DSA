
//T.C = 0(n)
//S.C = 0(1)

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> alpha(26, 0);  // A vector of 26 elements initialized to false (0)
        
        // Mark each letter that appears in the sentence
        for (int i = 0; i < sentence.size(); i++) {
            alpha[sentence[i] - 'a'] = 1;
        }

        // Check if all 26 letters are present
        for (int i = 0; i < 26; i++)
            if (alpha[i] == 0)
                return false;

        return true;
    }
};