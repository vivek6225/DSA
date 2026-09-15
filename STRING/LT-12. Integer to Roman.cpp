
// T.C. → O(1)  (The input num is limited to 3999, so the while loop can also run only a bounded number of times.)

// S.C. → O(1)  (The Roman numeral system has a fixed number of symbols, and the output has bounded size for num ≤ 3999.)

class Solution {
public:
    string intToRoman(int num) {
        // Roman values from largest to smallest
       vector<int> values = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };

        // Corresponding Roman symbols
         vector<string> symbols = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" }; 
         
         string result = "";

         // Start from the largest value
         for(int i = 0;i<values.size(); i++){

            // Keep using the current Roman value 
            // while it can be subtracted from num
               while(num >= values[i]){
                
                // Add the Roman symbol
                result +=symbols[i];

                // Reduce the number
                num -= values[i];
            }
         }
         return result;
    }
};