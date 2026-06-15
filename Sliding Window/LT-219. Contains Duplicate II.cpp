// T.C. = O(n)
// S.C. = O(k)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> st;

        int i = 0, j = 0;

        while (j < n) {

            // Keep window size at most k
            if (j - i > k) {
                st.erase(nums[i]);
                i++;
            }

            // Duplicate found within current window
            if (st.find(nums[j]) != st.end()) {
                return true;
            }

            st.insert(nums[j]);
            j++;
        }

        return false;
    }
};