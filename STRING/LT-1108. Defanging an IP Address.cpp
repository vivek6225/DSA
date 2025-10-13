
//T.C = 0(n)
//S.C = 0(n)

class Solution {
public:
    string defangIPaddr(string address) {
        string ans;  // To store the defanged IP address

        // Use a for loop to iterate through each character
        for (int i = 0; i < address.size(); i++) {
            // If the character is '.', replace with "[.]"
            if (address[i] == '.')
                ans += "[.]";
            else
                ans += address[i];  // Otherwise, add the character as it is
        }

        return ans;  // Return the final defanged address
    }
};