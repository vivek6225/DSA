
//----------------Optimal Approach------------------------------
//T.C: O(n)
//S.C: O(k)

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int total = 0;
        int n = nums.size();
        unordered_map<int,int> freq; // store frequency of elements in current window
        int start = 0, end = 0, count = 0;

        // --------------------------
        // Idea: Exactly(k) = AtLeast(k) - AtLeast(k+1)
        // --------------------------

        // Count subarrays with at least k distinct integers
        while(end < n) {
            freq[nums[end]]++;
            if(freq[nums[end]] == 1) // new distinct element
                count++;

            // Shrink the window until distinct elements < k
            while(count == k) {
                total += n - end; // all subarrays ending from 'end' to 'n-1' are valid
                freq[nums[start]]--;
                if(freq[nums[start]] == 0)
                    count--;
                start++;
            }
            end++;
        }

        // Reset for counting subarrays with at least (k+1) distinct elements
        start = 0;
        end = 0;
        count = 0;
        freq.clear();
        k++; // now count at least k+1 distinct elements

        while(end < n) {
            freq[nums[end]]++;
            if(freq[nums[end]] == 1)
                count++;

            while(count == k) {
                total -= n - end; // remove subarrays that have more than k distinct elements
                freq[nums[start]]--;
                if(freq[nums[start]] == 0)
                    count--;
                start++;
            }
            end++;
        }

        return total; // total subarrays with exactly k distinct integers
    }
};

//----------------brute force approach---------------------------
// Time Complexity: O(n²)
// Space Complexity: O(k)

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int total = 0;
        
        // Outer loop → select the starting index of the subarray
        for (int i = 0; i < n; i++) {
   // Use a set to track distinct integers in the current subarray
             unordered_set<int> distinct;

            // Inner loop → expand the subarray to the right
            for (int j = i; j < n; j++) {
                distinct.insert(nums[j]); // add current element to the set

                // if number of distinct elements exceeds k, break
                if (distinct.size() > k) break;

              // if number of distinct elements equals k, count it
                if (distinct.size() == k)
                    total++;
            }
        }

        return total;
    }
};