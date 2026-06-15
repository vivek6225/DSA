//---------Optimal mApproach----------------------
//T.C = O(n)
//T.C = O(n)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        // Stores: number -> its most recent index
        unordered_map<int, int> m;

        // Traverse the array
        for (int i = 0; i < nums.size(); i++) {

            // Check if current number has appeared before
            if (m.find(nums[i]) != m.end() &&

                // Distance between current index and previous index
                // of the same number is at most k
                abs(m[nums[i]] - i) <= k) {

                return true;
            }

            // Update the latest index of the current number
            m[nums[i]] = i;
        }

        // No nearby duplicate found
        return false;
    }
};

//---------Brute Force mApproach----------------------

//T.C = O(n²)
//S.C - O(1)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {

                // Check if duplicate exists within distance k
                if (nums[i] == nums[j] && abs(i - j) <= k) {
                    return true;
                }
            }
        }

        return false;
    }
};