             
             //  Brute Force Approach
    //T.C: O(n * k)
      //S.C: O(1)

                //Approach (Brute Force)

// 1.Traverse from left to right through the array.
// 2.If you see a 0 at position i:
//      .You must flip starting from i, because this 0 must turn into 1.
//        .Check if a window of size k fits inside the array (i + k - 1<n
//          .If not, return -1 (impossible to flip this 0).
//          . Otherwise, flip all k elements from index i to i + k - 1.
//          .Flipping is done using nums[j] = !nums[j].
//         . Increase the flip counter.
// 3. Continue until the end of the array.
// 4.Return the total number of flips.


class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int flip = 0;             // count of flips performed
        int n = nums.size();      // size of input array

        // Traverse through the array
        for (int i = 0; i < n; i++) {
            
     // If current bit is 0, we must flip starting from here
            if (nums[i] == 0) {
                
   // Check if flipping is possible (window of size k fits inside array)
                if (i + k - 1 >= n)
                    return -1;    // Not enough space → impossible to flip all to 1

       // Flip k consecutive elements starting from i
                for (int j = i; j <= i + k - 1; j++) {
                    nums[j] = !nums[j];   // toggle 0 → 1 or 1 → 0
                }

                flip++; // increment flip count
            }
        }

        return flip; // return the minimum number of flips required
    }
};
//----------------------------------------------------------------------
         // Optimal Approach
  //T.C = 0(n)
    //S.C = 0(n)
    class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        queue<int> q; 
        int flip = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
      // remove expired flips (jo window ke bahar chale gaye)
            if (!q.empty() && q.front() < i)
                q.pop();

  // ab check karo: agar flips ka parity == nums[i]
    // iska matlab element abhi effectively '0' hai → flip karna hoga
            if (q.size() % 2 == nums[i]) {
                if (i + k - 1 >= n)  // agar window bahar ja rahi hai
                    return -1;
                q.push(i + k - 1);   // mark ki flip yaha tak chalega
                flip++;
            }
        }
        return flip;
    }
};
