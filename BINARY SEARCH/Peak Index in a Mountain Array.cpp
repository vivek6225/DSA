class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int start = 1, end = n-2;
        while(start <= end){
            int mid = start + (end-start)/2;

            if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]){
                return mid;
            }
            //  incresing --> right search
            if(arr[mid-1] < arr[mid]){ 
                start = mid+1;

            }
            else{
                end = mid-1;
            }
        }
        return -1;
        
    }
};