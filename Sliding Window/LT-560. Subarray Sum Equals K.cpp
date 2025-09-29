     
  //                  Optimal Approach
  // T.C = 0(n)
  //S.c = 0(1)
  //1.Maintain a running prefix sum while iterating through the array.
//2.At each index i, check if there exists a prefix sum prefixSum - k in the map.
       // .This means there is a subarray ending at i whose sum   is exactly k.

//3.Use a hashmap m to store how many times each prefix sum has occurred.
//4.Add m[prefixSum - k] to the result whenever it exists.
//5.Update the frequency of current prefixSum in the map.

 // T.C = 0(n)
  //S.c = 0(1)
  class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        // prefixSum -> frequency
        unordered_map<int, int> m;
        int prefixSum = 0;
        int total = 0;

        // Initialize with 0 sum seen once (important for subarrays starting from index 0)
        m[0] = 1;

        for (int i = 0; i < n; i++) {
            prefixSum += nums[i]; // update running prefix sum

            // Check if there exists a prefixSum-k
            // If yes, then subarray from that index+1 to i has sum = k
            if (m.count(prefixSum - k)) {
                total += m[prefixSum - k];
            }

            // Store/update frequency of current prefixSum
            m[prefixSum]++;
        }

        return total; // total number of subarrays with sum = k
    }
};
     //------------------------------------------------------------
     // Better Approach
// .Fix a starting index (i) of subarray.
//. Expand subarray ending index (j).
// .Maintain a running sum (sum) while moving j.
// .If at any point sum == k, increment total.
//. Continue until all possible subarrays are checked.
 
// T.C= 0(n²)
//S.C = 0(1)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int total = 0; // to count number of subarrays with sum = k

        // Outer loop → choose starting index of subarray
        for (int i = 0; i < n; i++) {
            int sum = 0; // reset sum for each new starting index

            // Inner loop → expand subarray till end
            for (int j = i; j < n; j++) {
                sum += nums[j]; // keep adding elements

                // If current subarray sum == k, count it
                if (sum == k) {
                    total++;
                }
            }
        }

        // Return total number of subarrays with sum = k
        return total;
    }
};
//-----------------------------------------------------------------
   //               Brute force Approach
   

 //1.  Brute Force Enumeration
//         .Loop over all possible starting points i (0 to n-1).
//         .For each i, loop over ending points j (i to n-1).
//         .Compute the sum of elements between i and j.
// 2.Check Condition
//     .If the subarray sum equals k, increment counter.
//3. Return Answer 

//T.C = 0(n³)
// S.C = 0(1)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int total  = 0;  // store count of subarrays whose sum = k

        // Step 1: Choose starting index of subarray
        for (int i = 0; i < n; i++) {

            // Step 2: Choose ending index of subarray
            for (int j = i; j < n; j++) {
                int sum = 0;  // reset sum for every (i, j) subarray

                // Step 3: Calculate sum of current subarray nums[i...j]
                for (int l = i; l <= j; l++) {
                    sum += nums[l];
                }

                // Step 4: Check if this subarray sum is equal to k
                if (sum == k) {
                    total++;  // found one valid subarray
                }
            }
        }

        // Step 5: Return total number of subarrays with sum = k
        return total;
    }
};
