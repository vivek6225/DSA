// -----------------------------optimal Approach-------------------------
// Time → O(n³) 
// Space → O(1)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();
        vector<vector<int>> ans;

        // Step 1: Sort the array (needed for two-pointer + duplicate handling)
        sort(nums.begin(), nums.end());

        // Step 2: Fix first element (i)
        for(int i = 0; i < n; i++){

            // Skip duplicate values for i
            if(i > 0 && nums[i] == nums[i-1]) continue;

            // Step 3: Fix second element (j)
            for(int j = i + 1; j < n; j++){

                // Skip duplicate values for j
                if(j > i+1 && nums[j] == nums[j-1]) continue;

                // Two pointers for remaining two elements
                int k = j + 1;      // left pointer
                int l = n - 1;      // right pointer

                // Step 4: Two-pointer search
                while(k < l){

                    // Calculate sum of four elements
                    long long sum =(long long) nums[i] + nums[j] + nums[k] + nums[l];

                    // If sum is smaller than target → increase it
                    if(sum < target){
                        k++;
                    }
                    // If sum is greater than target → decrease it
                    else if(sum > target){
                        l--;
                    }
                    else{
                        // Found a valid quadruplet
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});

                        // Move both pointers
                        k++;
                        l--;

                        // Skip duplicates for k (left pointer)
                        while(k < l && nums[k] == nums[k-1]) k++;

                        // Skip duplicates for l (right pointer)
                        while(k < l && nums[l] == nums[l+1]) l--;
                    }
                }
            }
        }

        return ans;
    }
};
// -----------------------------Better Approach-------------------------
// T.C = O(n³ log n)
//. S.C = O(n³)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();

        // Set to store unique quadruplets (avoids duplicates automatically)
        set<vector<int>> st;

        // Fix first element
        for(int i = 0; i < n - 2; i++) {

            // Fix second element
            for(int j = i + 1; j < n - 1; j++) {

                // Hash set to store elements seen so far for current (i, j)
                // Helps in finding the 4th element in O(1)
                set<int> hash;  

                // Traverse for third element
                for(int k = j + 1; k < n; k++) {

                    // Sum of first three elements
                    int sum3 = nums[i] + nums[j] + nums[k];

                    // Required fourth element to reach target
                    int fourth = target - sum3;

                    // Check if required element already exists in hash
                    if(hash.find(fourth) != hash.end()) {

                        // Valid quadruplet found
                        vector<int> temp = {nums[i], nums[j], nums[k], fourth};

                        // Sort to maintain order (important for removing duplicates)
                        sort(temp.begin(), temp.end());

                        // Insert into set (duplicates automatically handled)
                        st.insert(temp);
                    }

                    // Store current element for future checks
                    hash.insert(nums[k]);  
                }
            }
        }

        // Convert set to vector and return result
        return vector<vector<int>>(st.begin(), st.end());
    }
};
//------------------Brute force approach ----------------------------
// Time Complexity: O(n^4 log M)
// Space Complexity: O(n²)

    // why not use unordered_set 
// “unordered_set requires a hash function, and since vector doesn’t have a built-in hash, we need to define a custom one.”

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        // Using set to store unique quadruplets (avoids duplicates automatically)
        set<vector<int>> st;

        // Pick first element
        for(int i = 0; i < n - 3; i++){
            
            // Pick second element
            for(int j = i + 1; j < n - 2; j++){
                
                // Pick third element
                for(int k = j + 1; k < n - 1; k++){
                    
                    // Pick fourth element
                    for(int l = k + 1; l < n; l++){
                        
                        // Check if sum of 4 elements equals target
                        if(nums[i] + nums[j] + nums[k] + nums[l] == target){
                            
                            // Store quadruplet
                            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                            
                            // Sort to maintain order (important for uniqueness in set)
                            sort(temp.begin(), temp.end());
                            
                            // Insert into set (duplicates automatically handled)
                            st.insert(temp);
                        }
                    }
                }
            }
        }

        // Convert set to vector for final answer
        vector<vector<int>> ans(st.begin(), st.end());
        
        return ans;
    }
};