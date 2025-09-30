
// T.C. = O(n log n + m log m)
// S.C. = O(min(n, m))

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        // Step 1: Sort both arrays so we can use two-pointer technique
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> ans;
        int i = 0, j = 0;

        // Step 2: Traverse both arrays using two pointers
        while (i < n && j < m) {
            
            if (nums1[i] < nums2[j]) {
                // If nums1 element is smaller, move pointer i
                i++;
            }
            else if (nums2[j] < nums1[i]) {
                // If nums2 element is smaller, move pointer j
                j++;
            }
            else {
                // nums1[i] == nums2[j] → common element found

                // Avoid duplicates: only push if ans is empty or last element is different
                if (ans.empty() || ans.back() != nums1[i]) {
                    ans.push_back(nums1[i]);
                }

            
                i++;
                j++;
            }
        }

        // Step 3: Return the result
        return ans;
    }
};