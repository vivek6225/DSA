
//T.C = 0(N)
//S.C = 0(1)

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();   
        int indx = 0;  // Pointer to write compressed characters

        // Step 1️: Traverse the entire array
        for (int i = 0; i < n; i++) {
            char ch = chars[i];  // Store the current character
            int count = 0;       // To count frequency of this character

            // Step 2️: Count consecutive occurrences of the same character
            while (i < n && chars[i] == ch) {
                count++;   // Increase count
                i++;       // Move to next character
            }

            // Step 3️: Write the character once in the compressed array
            chars[indx++] = ch;

            // Step 4️: If the character appeared more than once,
            //           convert count to string and add each digit
            if (count > 1) {
                string str = to_string(count);   // Convert number to string
                for (char dig : str) {
                    chars[indx++] = dig;        // Add each digit of count
                }
            }

            // Step 5️: Decrement i because 'for' loop will increment it again
            // (we already moved one extra step in the while loop)
            i--;
        }

        // Step 6️: Resize vector to contain only the compressed portion
        chars.resize(indx);

        // Step 7️: Return the new length after compression
        return indx;
    }
};