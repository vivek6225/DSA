//T.C = 0(N)
//S.C = 0(1)
//  Approach: Two Pointers

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0, end = numbers.size() - 1;

        while (start < end) {
            int sum = numbers[start] + numbers[end];

            if (sum == target) {
                return {start + 1, end + 1}; // 1-based index as per LeetCode
            } 
            else if (sum < target) {
                start++;
            } 
            else {
                end--;
            }
        }

        return {}; // return empty vector if no pair found
    }
};
