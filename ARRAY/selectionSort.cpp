class Solution
{
    public:
    int select(int arr[], int i,int n )
    {
        
        // code here such that selectionSort() sorts arr[]
        // Function to select the minimum element's index in the remaining unsorted part of the array
  
        int minIndex = i;  // Assume the first unsorted element is the minimum
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;  // Update minIndex if a smaller element is found
            }
        }
        return minIndex;  // Return the index of the minimum element
    
    }
     
 
       //code here
       // Function to perform selection sort
    void selectionSort(int arr[], int n) {
        for (int i = 0; i < n - 1; i++) {
            int minIndex = select(arr, i, n);  // Find the index of the minimum element
            // Swap the current element with the minimum element found
            if (minIndex != i) {
                swap(arr[i], arr[minIndex]);
            }
        }
    }
};