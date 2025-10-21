
//-------------Brute Force Approach-------------------------------------------
 
//T.C = 0(N²)
//S>C = 0(1) 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        
        for (int i = 0; i < s.size(); i++) {
            unordered_set<char> seen;  // to store unique characters
            for (int j = i; j < s.size(); j++) {
                if (seen.count(s[j]))  // if duplicate found, stop
                    break;
                seen.insert(s[j]);
                maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};

//---------------------------Optimal Approach-----------------------------------

//T.c = 0(N)
//S.C = 0(1)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     
        vector<bool> count(256, 0); // 256 covers all ASCII characters
        
        int first = 0;   
        int second = 0;  
        int length = 0;  
        
        while (second < s.size()) {

            // If current character is already in window (duplicate found)
            while (count[s[second]]) {
                // Remove characters from the left until duplicate is removed
                count[s[first]] = 0;
                first++; // shrink the window from the left
            }

            // Include the current character in the window
            count[s[second]] = 1;

            // Update the maximum length of substring found so far
            length = max(length, second - first + 1);

            // Move the right pointer ahead to explore further
            second++;
        }

        
        return length;
    }
};