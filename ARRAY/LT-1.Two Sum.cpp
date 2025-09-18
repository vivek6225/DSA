
                            // optimal Approach
              //T.C = 0(n)
              //S.c = 0(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> m;   // stores {value → index} for quick lookup
        vector<int> ans;            // to store the result (two indices)
        
        for (int i = 0; i < nums.size(); i++) {
            int first = nums[i];           // current number
            int second = target - first;   // the number we need to find
            
            // check if the required 'second' number already exists in map
            if (m.find(second) != m.end()) {
                ans.push_back(i);          // current index
                ans.push_back(m[second]);  // index of the required number
                break;                     // solution found, break the loop
            }
            
            // store the current number with its index in the map
            m[first] = i;
        }
        
        return ans; // return the pair of indices
    }
};

//-----------------------------------------------------------------------------------------
         //  Better Approach
        //  T.C = 0(n log n)
        //  S.C = 0(n)

            //  What is a pair<int,int>?
//  A pair is a container that stores two values together.
// Example :- pair<int,int> p = {9, 0};
// p.first = 9 → the value from the array
//p.second = 0 → the original index of that value


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> arr;  // store {value, index}

 // Build an array of pairs to store each value with its original index
        for (int i = 0; i < nums.size(); i++) {
            arr.push_back({nums[i], i}); // nums[i] → the actual value in the array,// i → the original index of that value
        }

        // sort by value
        sort(arr.begin(), arr.end());   // 0(n lon n)

        int start = 0, end = arr.size() - 1; // Two pointers → O(n)
        while (start < end) {
            int sum = arr[start].first + arr[end].first;

            if (sum == target) {
                // return original indices
                return {arr[start].second, arr[end].second};
            } 
            else if (sum > target) {
                end--;
            } 
            else {
                start++;
            }
        }

        return {}; // no solution
    }
};

//-----------------------------------------------------------------------------------------
                            // Brute force Approach
    // T.C = 0(n*n)
    //S.C = 0(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};