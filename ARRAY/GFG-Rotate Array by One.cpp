
//Time Complexity: O(n)
//Auxiliary Space: O(1)
class Solution {
  public:
    void rotate(vector<int> &arr) {

        int n = arr.size();
        int last = arr.back(); // save the last element
        for(int i = n-2; i>=0; i--)
        arr[i+1] = arr[i]; // shift element to right
        arr[0] = last;  // place last holder in the 1st position
    }
};