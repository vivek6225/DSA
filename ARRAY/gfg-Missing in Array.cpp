
// Time Complexity: O(n)
// Auxiliary Space: O(1)

class Solution {
public:
    int missingNum(vector<int>& arr) {

        long long actualSum = 0;
        long long n = (long long)arr.size() + 1; // total numbers should be n
        
        for (int i = 0; i < arr.size(); i++) 
            actualSum += (long long)arr[i];  
        
        long long expectedSum = n * (n + 1) / 2; // computed in 64-bit
        return (int)(expectedSum - actualSum);

    }
};
