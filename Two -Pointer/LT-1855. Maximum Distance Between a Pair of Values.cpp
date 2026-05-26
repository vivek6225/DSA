//---------- Optimal Approach -------------------
//Time Complexity:O(n+m)
//Space Complexity:O(1)

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {

        int dist = 0;

        // Two pointers
        int i = 0;
        int j = 0;

        // Traverse both arrays
        while(i < nums1.size() && j < nums2.size()) {

            // Invalid pair
            // nums1[i] must be <= nums2[j]
            if(nums1[i] > nums2[j]) {

                // Move i to find smaller value
                i++;
            }
            else {

                // Valid pair found
                dist = max(dist, j - i);

                // Try to increase distance
                j++;
            }
        }

        return dist;
    }
};
//------ Brute Force Approach ----------
//Time Complexity:O(n²)
//Space Complexity:O(1)
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {

        int dist = 0;

        for(int i = 0; i < nums1.size(); i++) {

            for(int j = i; j < nums2.size(); j++) {

                // valid pair condition
                if(nums1[i] <= nums2[j]) {
                    dist = max(dist, j - i);
                }
            }
        }

        return dist;
    }
};