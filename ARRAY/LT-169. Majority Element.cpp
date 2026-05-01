      //-------------Optimal Approach---------------------
    //                Boyer–Moore Voting Algorithm
    //   Moore’s Voting Algorithm finds the majority element using a candidate and count variable. Different elements cancel each other out, and the majority element survives in the end. It works in O(n) time and O(1) space.

      
        // T.C: O(n)
        // S.C: O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        int count = 0;   // stores vote count
        int ans = 0;     // stores current candidate

        // Boyer–Moore Voting Algorithm
        for (int i = 0; i < n; i++) {

            // if count becomes 0,
            // choose current element as new candidate
            if (count == 0) {
                ans = nums[i];
            }

            // same element -> increase vote count
            if (nums[i] == ans) {
                count++;
            }
            // different element -> decrease vote count
            else {
                count--;
            }
        }

        // remaining candidate is majority element
        return ans;
    }
};


//-------------Better Approach--------------------------

// Time Complexity: O(n log n) (due to sorting)
// Space Complexity: O(1)
 // Approach:
        // 1. Sort the array.
        // 2. The majority element (appearing more than n/2 times)
        //    will always occupy the middle position or dominate one half.
        // 3. Count occurrences to confirm and return it.
class Solution {
public:
    int majorityElement(vector<int>& nums) {
       
        int n = nums.size();

        // Step 1: Sort the array to group identical elements together
        sort(nums.begin(), nums.end());
      
        int count = 1;        // to count frequency of the current element
        int ans = nums[0];    // assume first element is the majority

        // Step 2: Traverse the sorted array and count consecutive duplicates
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i - 1]) {
                count++;  // same element -> increment count
            } else {
                // reset count when element changes
                count = 1;
                ans = nums[i];
            }

            // Step 3: if frequency > n/2, return immediately
            if(count > n / 2) {
                return ans;
            }
        }

        // Step 4: return the found element
        return ans;
    }
};

//-------------Brute Force Approach------------------
//T.c= 0(n²)
//S.c = 0(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        for(int  i = 0; i<n; i++){
            int count = 0;
            for(int  j = 0; j<n; j++){
                if(nums[j] == nums[i])
                count++;
            }
            if(count > n/2)
            return nums[i];
         }
         return -1;
        
    }
};