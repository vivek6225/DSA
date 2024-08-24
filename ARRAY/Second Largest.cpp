class Solution {
  public:
    // Function returns the second
    // largest elements
    int print2largest(vector<int> &arr) {
  
        int largest = -1;
        //largest element 
        for(int i = 0; i<arr.size(); i++)
        {
            if(arr[i]>largest)
            largest = arr[i];
        }
        
        // second largest 
        int second =  -1;
        for(int i = 0; i<arr.size(); i++)
        {
            if(arr[i]!=largest)
            second = max(second,arr[i]);
        }
        return second;
        
    }
};