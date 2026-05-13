//----------Optimal Approach-------------
//T.C = 0(n)
//S.c = 0(n)
              //Approach
// Use a running prefix sum while traversing the array.
// Keep a hashmap of prefix sum frequencies.
// If a prefix sum repeats, the subarray(s) between previous occurrence(s) and current index has sum = 0.

class Solution {
public:

    int findSubarray(vector<int> &arr) {

        int n = arr.size();

        // Stores final count of zero sum subarrays
        int count = 0;

        // Stores running prefix sum
        int prefixSum = 0;

        // Map -> {prefixSum, frequency}
        unordered_map<int,int> m;

        // Important:
        // If prefix sum itself becomes 0,
        // then subarray from 0 to i has sum 0
        m[0] = 1;

        for(int i = 0; i < n; i++) {

            // Update prefix sum
            prefixSum += arr[i];

            // If same prefix sum already exists,
            // then zero sum subarray found
            if(m.count(prefixSum)) {

                // Add previous frequency
                count += m[prefixSum];

                // Increase frequency
                m[prefixSum]++;
            }
            else {

                // First occurrence of prefix sum
                m[prefixSum] = 1;
            }
        }

        return count;
    }
};
        
       
//------------------ Better Approach----------
// T.C= 0(n²)
// S.C = 0(1)
             // Approach
   //Avoid the innermost loop by accumulating sum from start index i to end index j.
class Solution {
public:
    int findSubarray(vector<int> &arr) {
        int n = arr.size();
        int total = 0;

        for (int i = 0; i < n; i++) {
            int sum = 0;  

            // Expand subarray ending at j
            for (int j = i; j < n; j++) {
                sum += arr[j]; // accumulate sum

                if (sum == 0) {
                    total++;
                }
            }
        }
        return total;
    }
};
//----------- Brute force approach--------------
// T.c = 0(n³)
// S.C  = 0(1)
 
// Approach
//Generate all subarrays and calculate their sum.

class Solution {
public:
    int findSubarray(vector<int> &arr) {
        int n = arr.size();   
        int total = 0;        

        // Choose the starting index of the subarray
        for (int i = 0; i < n; i++) {
            // Choose the ending index of the subarray
            for (int j = i; j < n; j++) {
                int sum = 0;  // store sum of current subarray

                // Calculate sum of subarray from index i to j
                for (int k = i; k <= j; k++) {
                    sum += arr[k];
                }

                // If the sum is 0, increase the counter
                if (sum == 0) {
                    total++;
                }
            }
        }

        // Return total number of subarrays with sum = 0
        return total;
    }
};
