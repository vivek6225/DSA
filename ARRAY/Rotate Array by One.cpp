class Solution {
  public:
    void rotate(vector<int> &arr) {
        int last = arr.back(); // save the last element 
        
        for(int i = arr.size()-2; i>=0; i-- )
        arr[i+1]=arr[i]; // shift element to the right 
        arr[0]=last; // place the last element to the first position
        
            }
};
