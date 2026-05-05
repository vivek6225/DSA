
//------------Optimal Approach------------------

// 1. Maintain a running prefix sum while iterating through the array.

// 2. At each index i, check if (prefixSum - k) exists in the map.
//    This means there is a subarray ending at index i whose sum is exactly k.

// 3. Use a hashmap 'm' to store the frequency of each prefix sum.

// 4. If (prefixSum - k) exists, add its frequency to the result.

// 5. Update the frequency of the current prefixSum in the map.

 // T.C = O(n)
  //S.c = O(n)
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
              // add number of times (prefixSum - k) appeared
                total += m[prefixSum - k];
            }

            // Store/update frequency of current prefixSum
            m[prefixSum]++;
        }

        return total; // total number of subarrays with sum = k
    }
};

//-----------------Better  Approach---------------
// Time Complexity	O(n²)
// Space Complexity	O(1)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int n = nums.size();     // size of array
        int total = 0;           // stores count of valid subarrays

        // choose starting index of subarray
        for(int i = 0; i < n; i++){

            int sum = 0;   // reset sum for each new starting point

            // extend subarray from i to j
            for(int j = i; j < n; j++){

                sum += nums[j];   // add current element to sum

                // if current subarray sum equals k
                if(sum == k){
                    total++;      // increment count
                }
            }
        }

        return total;   // return total number of subarrays
    }
};



