//------------------------optimal Approach----------------------
//T.C = O(n² )
// S.C =  O(1)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> ans;

        // Step 1: Sort the array (important for two-pointer + duplicate handling)
        sort(nums.begin(), nums.end());

        // Step 2: Fix the first element
        for(int i = 0; i < n; i++){

            // Skip duplicate values of i to avoid repeated triplets
            if(i > 0 && nums[i] == nums[i-1]) continue;

            // Two pointers for remaining part
            int j = i + 1;        // left pointer
            int k = n - 1;        // right pointer

            // Step 3: Find pairs such that sum = 0
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];

                // If sum is too small → increase it
                if(sum < 0){
                    j++;
                }
                // If sum is too large → decrease it
                else if(sum > 0){
                    k--;
                }
                else{
                    // Found a valid triplet
                    ans.push_back({nums[i], nums[j], nums[k]});

                    // Move both pointers
                    j++;
                    k--;

                    // Skip duplicate values for j (left pointer)
                    while(j < k && nums[j] == nums[j-1]) j++;

                    // Skip duplicate values for k (right pointer)
                    while(j < k && nums[k] == nums[k+1]) k--;
                }
            }
        }

        return ans;
    }
};
//------------------------Better Approach------------------------

//T.C = O(n² log n)
// S.C =  O(n²)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();

        // Set to store unique triplets
        set<vector<int>> st;

        // Fix first element
        for(int i = 0; i < n; i++){

            // Hash set to store elements seen for current i
            set<int> hash;

            // Traverse remaining array
            for(int j = i+1; j < n; j++){

                // We want nums[i] + nums[j] + third = 0
                int third = -(nums[i] + nums[j]);

                // Check if third element already exists
                if(hash.find(third) != hash.end()){

                    // Valid triplet found
                    vector<int> temp = {nums[i], nums[j], third};

                    // Sort to maintain order (for uniqueness)
                    sort(temp.begin(), temp.end());

                    // Insert into set (duplicates automatically removed)
                    st.insert(temp);
                }

                // Store current element for future checks
                hash.insert(nums[j]);
            }
        }

        // Convert set to vector
        vector<vector<int>> ans(st.begin(), st.end());

        return ans;
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

