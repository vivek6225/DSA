class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        int largest = arr[0];
        int seclargest =  -1;
        for(int  i = 1; i<n; i++){
           // Case 1: Found a new largest element
            if(arr[i] > largest){
            seclargest = largest; // old largest becomes second largest
           largest = arr[i];  // update largest
            }
            else if(arr[i] < largest && arr[i] > seclargest){
                seclargest = arr[i];
            }
        }
           return seclargest;
     
    }
};