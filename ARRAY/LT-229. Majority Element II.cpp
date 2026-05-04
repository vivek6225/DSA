// ----------------------Optimal Approach-------------------
// Time	O(n)
// Space O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size();

        int count1 = 0, count2 = 0;        // counters for two candidates
        int candidate1 = 0, candidate2 = 0; // potential majority elements

        // -------- Step 1: Find potential candidates --------
        for(int i = 0; i < n; i++){

            // if current element matches candidate1
            if(nums[i] == candidate1){
                count1++;
            }
            // if matches candidate2
            else if(nums[i] == candidate2){
                count2++;
            }
            // if count1 becomes 0, choose new candidate1
            else if(count1 == 0){
                candidate1 = nums[i];
                count1 = 1;
            }
            // if count2 becomes 0, choose new candidate2
            else if(count2 == 0){
                candidate2 = nums[i];
                count2 = 1;
            }
            // if current element matches neither → cancel both
            else{
                count1--;
                count2--;
            }
        }

        // -------- Step 2: Verify actual frequency --------
        count1 = 0;
        count2 = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == candidate1){
                count1++;
            }
            else if(nums[i] == candidate2){
                count2++;
            }
        }

        vector<int> ans;  // stores final majority elements

        // check if candidates appear more than n/3 times
        if(count1 > n/3){
            ans.push_back(candidate1);
        }
        if(count2 > n/3){
            ans.push_back(candidate2);
        }

        return ans;  // return result
    }
};
//--------------------------------Better Approach---------
// Time Complexity	O(n)
// Space Complexity	O(n)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans;   // stores final majority elements

        unordered_map<int, int> mp;   // map to store frequency (number → count)

        // Step 1: count frequency of each element
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;   // increase count of nums[i]
        }

        // Step 2: check which elements appear more than n/3 times
        for(auto it : mp){

            // it.first  → element (key)
            // it.second → frequency (value)

            if(it.second > n/3){   // condition for majority element
                ans.push_back(it.first);   // add element to result
            }
        }

        return ans;   // return all majority elements
    }
};
//---------------Brute Force Approach---------------------------------------------
// Time: O(n²)
// Space: O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans;   // stores majority elements

        // pick each element one by one
        for(int i = 0; i < n; i++){

            int count = 0;   // count frequency of nums[i]

            // count occurrences of nums[i]
            for(int j = 0; j < n; j++){

                if(nums[i] == nums[j]){
                    count++;
                }
            }

            // if element appears more than n/3 times
            if(count > n/3){

                bool found = false;   // check duplicate element

                // check whether element already exists in ans
                for(int k = 0; k < ans.size(); k++){

                    if(ans[k] == nums[i]){
                        found = true;
                        break;
                    }
                }

                // add element if not already present
                if(!found){
                    ans.push_back(nums[i]);
                }
            }
        }

        return ans;   // return all majority elements
    }
};