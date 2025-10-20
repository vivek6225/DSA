
// T.C = 0(N)
// S.C = 0(1)
class Solution {
public:
    // Function to return integer value of a Roman character
    int num(char c) {
        if (c == 'I') return 1;
        if (c == 'V') return 5;
        if (c == 'X') return 10;
        if (c == 'L') return 50;
        if (c == 'C') return 100;
        if (c == 'D') return 500;
        return 1000; // 'M'
    }

    int romanToInt(string s) {
        int sum = 0;      // to store final integer value
        int index = 0;    // pointer to traverse the string

        // Traverse each character except the last one
        while (index < s.size() - 1) {
            // If current value is less than next value,
            // subtract current value (like IV = 5 - 1 = 4)
            if (num(s[index]) < num(s[index + 1])) 
                sum -= num(s[index]);
            else
                // Otherwise, add the current value (like VI = 5 + 1 = 6)
                sum += num(s[index]);
            
            index++;  // move to next character
        }

        // Add the last Roman symbol’s value
        sum += num(s[index]);

        return sum;  // return the final integer
    }
};

