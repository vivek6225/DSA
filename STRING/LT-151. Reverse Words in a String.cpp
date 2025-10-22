

// T.C = 0(N)
// S.C = 0(N)

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();       
        string ans = "";       
        
        // Step 1: Reverse the entire string
        reverse(s.begin(), s.end());

        // Step 2: Traverse through the reversed string
        for (int i = 0; i < n; i++) {
            string word = "";   // Temporary string to store each word
            
            // Step 3: Extract characters until a space is found
            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }
            
            // Step 4: Reverse the extracted word to restore its original order
            reverse(word.begin(), word.end());

            // Step 5: If word is not empty, append it to the result with a space
            if (word.length() > 0)
                ans += " " + word;
        }

        // Step 6: Remove the leading space before returning
        return ans.substr(1);
    }
};
