
//T.C = 0(n+m)
//S.C = 0(1)

class Solution {
public:
    string minWindow(string s, string t) {
        //  Step 1: Initialize data structures
        int total = t.size();        // total characters we still need to match
        vector<int> m(256, 0);  // frequency map for all ASCII characters

        // Store frequency of each character in string t
        for (int i = 0; i < t.size(); i++) {
            m[t[i]]++;
        }

        // Two pointers for sliding window
        int start = 0, end = 0;
        int ans = INT_MAX;       // minimum window length found
        int index = -1;         // starting index of the best window

        //  Step 2: Expand the window using 'end' pointer
        while (end < s.size()) {
            m[s[end]]--;             // include current character in the window

            // If this character was needed (count was positive before decrement)
            if (m[s[end]] >= 0)
                total--;      // reduce remaining required characters

            //  Step 3: Try to shrink the window from the left if all chars are found
            while (total == 0 && start <= end) {
                // Update answer if current window is smaller
                if (ans > end - start + 1) {
                    ans = end - start + 1;
                    index = start;
                }

                // Remove s[start] from the window
                m[s[start]]++;
                if (m[s[start]] > 0)       // if this char was part of t
                    total++;               // we need it again
                start++;                   // shrink the window
            }

            //  Step 4: Move 'end' to expand the window
            end++;
        }

        //  Step 5: Return result
        if (index == -1)    // no valid window found
            return "";

        // Build and return substring from index to index + ans
        string str = "";
        for (int i = index; i < index + ans; i++) {
            str += s[i];
        }
        return str;
    }
};