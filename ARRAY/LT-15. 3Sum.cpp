//------------------------optimal Approach----------------------
//T.C = O(n² )
// S.C =  O(1)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Fix first element (i)
        for(int i = 0; i < nums.size(); i++) {

            // Skip duplicate values of i
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int left = i + 1;                 // second element
            int right = nums.size() - 1;      // third element

            // Step 3: Two pointer search
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if(sum == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicates for left
                    while(left < right && nums[left] == nums[left+1]) left++;

                    // Skip duplicates for right
                    while(left < right && nums[right] == nums[right-1]) right--;

                    left++;
                    right--;
                }
                else if(sum < 0) {
                    left++;   // need bigger sum
                }
                else {
                    right--;  // need smaller sum
                }
            }
        }

        return ans;
    }
};
//------------------------Better Approach----------------------

//T.C = O(n² log n)
// S.C =  O(n²)
class Solution {
public:

    // Binary Search function to check if target exists in nums[left...right]
    bool binarySearch(vector<int>& nums, int left, int right, int target) {

        // Standard binary search loop
        while (left <= right) {
            int mid = left + (right - left) / 2;

            // If target found
            if(nums[mid] == target) return true;

            // If target is greater, search right half
            else if(nums[mid] < target) left = mid + 1;

            // If target is smaller, search left half
            else right = mid - 1;
        }

        // Target not found
        return false;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        // Set is used to store only UNIQUE triplets
        set<vector<int>> st;

        // Sort the array for binary search and duplicate handling
        sort(nums.begin(), nums.end());

        // Fix the first element
        for(int i = 0; i < n-2; i++){

            // Fix the second element
            for(int j = i+1; j < n-1; j++){

                // Find the third value such that sum = 0
                // nums[i] + nums[j] + target = 0
                int target = -(nums[i] + nums[j]);

                // Search for target in remaining part of array
                if(binarySearch(nums, j+1, n-1, target)){

                    // Create the triplet
                    vector<int> temp = {nums[i], nums[j], target};

                    // Sort triplet to maintain consistent order
                    // (important for removing duplicates)
                    sort(temp.begin(), temp.end());

                    // Insert into set (duplicates automatically removed)
                    st.insert(temp);
                }
            }
        }

        // Convert set to vector and return result
        return vector<vector<int>>(st.begin(), st.end());
    }
};
//-------------------Brute Force Approach------------------------------- 
//T.C = O(n³)
//S.C = O(n²)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        // set is used to automatically store only UNIQUE triplets
        set<vector<int>> st;

        // Try all possible triplets (Brute Force - O(n^3))
         for(int i = 0; i < n-2; i++){
           for(int j = i + 1; j < n-1; j++){
             for(int k = j + 1; k < n; k++){

                    // Check if sum of three elements is zero
                    if(nums[i] + nums[j] + nums[k] == 0){

                        // Store the triplet
                        vector<int> temp = {nums[i], nums[j], nums[k]};

                        // Sort the triplet to maintain a fixed order
                        // (important for removing duplicates like [0,-1,1] and [-1,0,1])
                        sort(temp.begin(), temp.end());

                        // Insert into set (duplicates automatically ignored)
                        st.insert(temp);
                    }
                }
            }
        }

        // Convert set to vector for final answer
        vector<vector<int>> ans(st.begin(), st.end());

        return ans;
    }
};

