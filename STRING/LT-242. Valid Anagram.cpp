//------------Optimal Approach---------------------
//T.C = O(N)
//S.C = O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {

        // If lengths are different, cannot be anagrams
        if(s.size() != t.size()){
            return false;
        }

        // Frequency array for 26 lowercase letters
        vector<int> freq(26, 0);

        // Count frequency of characters in s
        for(int i = 0; i < s.size(); i++){
            freq[s[i] - 'a']++;
        }

        // Decrease frequency using characters of t
        for(int j = 0; j < t.size(); j++){
            freq[t[j] - 'a']--;
        }

        // If any frequency is not 0, not an anagram
        for(int i = 0; i < 26; i++){
            if(freq[i] != 0){
                return false;
            }
        }

        return true;
    }
};
//--------Better Approach---------------------
//Time Complexity: O(n log n)
//Space Complexity:O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {

       // If sizes are different, they cannot be anagrams
       if(s.size() != t.size()){
            return false;
       } 

       // Sort both strings
       sort(s.begin(), s.end());
       sort(t.begin(), t.end());

       // After sorting, anagrams become equal
       return s == t;
    }
};

//--------Brute force Approach----------------
//T.C = O(n²)
//S.C = O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {

       // If sizes are different, cannot be anagrams
       if(s.size() != t.size()){
            return false;
       } 

       // Traverse each character of s
       for(int i = 0; i < s.size(); i++){

            bool found = false;

            // Search current character in t
            for(int j = 0; j < t.size(); j++){

                // Character matched
                if(s[i] == t[j]){

                    found = true;

                    // Mark character as used
                    t[j] = '#';

                    // Stop searching further
                    break;
                }
            }

            // Character not found in t
            if(!found){
                return false;
            }
       }

       return true;
    }
};