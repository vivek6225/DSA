
 //T.Cn = 0(N)
 //S.C = 0(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSubString(string& str) {
        // Step 1: Initialize frequency array for all ASCII characters
        vector<int> count(256, 0);
        
        int first = 0, second = 0;
        int length = str.size();  
        int different = 0;  

        // Step 2: Count total number of distinct characters in the string
        while (first < str.size()) {
            if (count[str[first]] == 0)  // if character appears for the first time
                different++;              // increment distinct count
            count[str[first]]++;          // increase its frequency
            first++;
        }

        // Step 3: Reset the frequency array for sliding window usage
        for (int i = 0; i < 256; i++)
            count[i] = 0;

        first = 0; // reset left pointer
        int have = 0; // how many distinct chars currently in the window

        // Step 4: Use sliding window technique to find smallest substring
        while (second < str.size()) {
            // expand the window
            count[str[second]]++;
            if (count[str[second]] == 1)
                have++; // new unique char found
            second++;

            // when window contains all distinct chars
            while (have == different) {
                length = min(length, second - first);

                // try to shrink from left
                count[str[first]]--;
                if (count[str[first]] == 0)
                    have--;
                first++;
            }
        }

        // Step 5: Return the minimum length of substring
        return length;
    }
};

