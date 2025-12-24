
//T.C = O(N log N)
//S.C = 0(N)
class Solution {
public:

    // This function merges two sorted parts of the array:
    // left part  -> start to mid
    // right part -> mid+1 to end
    void merge(vector<int>& arr, int start, int mid, int end)
    {
        // Temporary array to store merged result
        vector<int> temp(end - start + 1);

        int left = start;     // pointer for left subarray
        int right = mid + 1;  // pointer for right subarray
        int index = 0;        // pointer for temp array

        // Compare elements from both halves
        while (left <= mid && right <= end)
        {
            if (arr[left] <= arr[right])
            {
                temp[index] = arr[left];
                index++, left++;
            }
            else
            {
                temp[index] = arr[right];
                index++, right++;
            }
        }

        // Copy remaining elements of left subarray
        while (left <= mid)
        {
            temp[index] = arr[left];
            index++, left++;
        }

        // Copy remaining elements of right subarray
        while (right <= end)
        {
            temp[index] = arr[right];
            index++, right++;
        }

        // Copy sorted values from temp back to original array
        index = 0;
        while (start <= end)
        {
            arr[start] = temp[index];
            start++, index++;
        }
    }

    // Recursive function to divide the array
    void mergesort(vector<int>& arr, int start, int end)
    {
        // Base case: only one element
        if (start == end)
            return;

        int mid = start + (end - start) / 2;

        // Sort left half
        mergesort(arr, start, mid);

        // Sort right half
        mergesort(arr, mid + 1, end);

        // Merge both sorted halves
        merge(arr, start, mid, end);
    }

    vector<int> sortArray(vector<int>& nums) {

        // Start merge sort on full array
        mergesort(nums, 0, nums.size() - 1);

        return nums;
    }
};