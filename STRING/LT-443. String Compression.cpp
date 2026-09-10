//T.C = 0(N)
//S.C = 0(1)

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();

        // index tells us where to write the compressed result
        int index = 0;

        // i moves through the original array
        for (int i = 0; i < n; ) {

            // Store the current character
            char ch = chars[i];

            // Count how many times the character appears consecutively
            int count = 0;

            // Count the same consecutive characters
            while (i < n && chars[i] == ch) {
                count++;
                i++;
            }

            // Write the character into the array
            chars[index] = ch;
            index++;

            // If character appears more than once,
            // write its count after the character
            if (count > 1) {

                // Convert count (integer) into string
                // Example: 12 -> "12"
                string s = to_string(count);

                // Write each digit of count into chars
                for (char c : s) {
                    chars[index] = c;
                    index++;
                }
            }
        }

        // Return the length of the compressed array
        return index;
    }
};


