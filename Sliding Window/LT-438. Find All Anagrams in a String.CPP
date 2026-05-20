//------------Optimal Approach---------------------
//T.C = 0(N)
//T.C = 0(1)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> ans;

        // If p is larger than s, anagram is not possible
        if(p.size() > s.size()) {
            return ans;
        }

        // Frequency arrays
        int sFreq[26] = {0};
        int pFreq[26] = {0};

        // Store frequency of p
        for(int i = 0; i < p.size(); i++) {

            // Convert character into index
            pFreq[p[i] - 'a']++;
        }

        int windowSize = p.size();

        // Sliding window
        for(int i = 0; i < s.size(); i++) {

            // Add current character into window
            sFreq[s[i] - 'a']++;

            // Remove left character when window exceeds size
            if(i >= windowSize) {

                sFreq[s[i - windowSize] - 'a']--;
            }

            bool isSame = true;

            // Compare both frequency arrays
            for(int j = 0; j < 26; j++) {

                if(sFreq[j] != pFreq[j]) {
                    isSame = false;
                    break;
                }
            }

            // If frequencies are same, anagram found
            if(isSame && i >= windowSize - 1) {

                ans.push_back(i - windowSize + 1);
            }
        }

        return ans;
    }
};
//------------better Approach---------------------
// Time Complexity:O(n * m)
// Space Complexity:O(1)

// Frequency array is faster because array indexing takes O(1), while map operations take O(log n).

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        // If p is larger than s, anagram is not possible
        if(p.size() > s.size()) {
            return ans;
        }

        // Traverse all possible substrings
        for(int i = 0; i <= s.size() - p.size(); i++) {

            // Frequency arrays for substring and p
            int sFreq[26] = {0};
            int pFreq[26] = {0};

            // Count frequency of characters
            for(int j = 0; j < p.size(); j++) {

                // Store frequency of substring characters
                sFreq[s[i + j] - 'a']++;

                // Store frequency of p characters
                pFreq[p[j] - 'a']++;
            }

            bool isSame = true;

            // Compare both frequency arrays
            for(int k = 0; k < 26; k++) {

                if(sFreq[k] != pFreq[k]) {
                    isSame = false;
                    break;
                }
            }

            // If frequencies are same, anagram found
            if(isSame) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
//---------Brute Force Approach----------------
//T.C = O(n * m * log m)
// S.C = O(1)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

       vector<int> ans;

       // If p is bigger than s, anagram is not possible
       if(p.size() > s.size()){
            return ans;
       }

       // Traverse all possible substrings
       for(int i = 0; i <= s.size() - p.size(); i++){
          
          Map<char,int> sMap;
          Map<char,int> pMap;

          // Store frequency of substring and p
          for(int j = 0; j < p.size(); j++){

            sMap[s[i + j]]++;
            pMap[p[j]]++;
          }

          // Compare both maps
          if(sMap == pMap){
            ans.push_back(i);
          }
       } 

        return ans;
    }
};