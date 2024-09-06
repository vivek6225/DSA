class Solution {
  public:
    // Function to return a list containing the intersection of two arrays.
    vector<int> printIntersection(vector<int> &arr1, vector<int> &arr2) {
        // Your code here
         int n = arr1.size();
        int m = arr2.size();
        int i = 0, j = 0;
        vector<int> ans;

        while(i < n && j < m) {
            if(arr1[i] < arr2[j]) {
                i++;
            }
            else if(arr2[j] < arr1[i]) {
                j++;
            }
            else {
                // To avoid adding duplicates, only add if the vector is empty or the last element added is different.
                if(ans.empty() || arr1[i] != ans.back())
                ans.push_back(arr1[i]);
                
                i++;
                j++;
            }
        }
        if(ans.size()) {
            return ans;
        }
        return  {-1};
    }
};