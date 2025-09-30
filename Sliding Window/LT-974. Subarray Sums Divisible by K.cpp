
                  //optimal Approach
//T.C= 0(n)
//S.C = 0(n)

  //. Steps:
//     1.Keep running prefixSum.
//     2.Compute rem = prefixSum % k (fix negative with rem += k).
//    3.Use hashmap m to store remainder frequencies.
//    4.Each time a remainder repeats → add m[rem] to count.
//    5.Increment m[rem].
// .Initialize m[0] = 1 to count subarrays starting from index 0.

Initialize m[0] = 1 to count subarrays starting from index 0.
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int total = 0;          // total count of subarrays
        int prefixSum = 0;      // running prefix sum
        int rem;                // remainder when prefixSum % k

        unordered_map<int, int> m; 
        m[0] = 1; // base case: one way to have remainder 0 initially

        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];      // update prefix sum
            rem = prefixSum % k;       // take remainder

            if (rem < 0) rem += k;     // fix negative remainder

            // If this remainder has been seen before,
            // then there are m[rem] subarrays ending at i that are divisible by k
            if (m.count(rem)) {
                total += m[rem];
                m[rem]++; // increment frequency
            } else {
                m[rem] = 1; // first time seeing this remainder
            }
        }

        return total;
    }
};

//-----------------------------------------------------------------
                        // Better Approach
//T.C = 0(n²)
//S.C = (1)

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int total = 0;

        // Check all subarrays
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];  // accumulate subarray sum
                if (sum % k == 0) {
                    total++;  // subarray (i..j) is divisible by k
                }
            }
        }
        return total;
    }
};
