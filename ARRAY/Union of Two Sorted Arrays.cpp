// Two-pointers method: Both arrays are traversed using pointers i and j.
// Conditionals: In each iteration, the smaller element between arr1[i] and arr2[j] is added to the unionArr, ensuring no duplicates are added.
// Remaining elements: After one of the arrays is fully traversed, any remaining elements in the other array are added to unionArr, again making sure no duplicates are included.

class Solution {
    public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
        int i = 0, j = 0;
        vector<int> unionArr;
        
        while(i < n && j < m) {
            if (arr1[i] <= arr2[j]) {
                if (unionArr.size() == 0 || unionArr.back() != arr1[i]) {
                    unionArr.push_back(arr1[i]);
                }
                i++;
            } else {
                if (unionArr.size() == 0 || unionArr.back() != arr2[j]) {
                    unionArr.push_back(arr2[j]);
                }
                j++;
            }
        }
        
        // Process remaining elements in arr1
        while(i < n) {
            if (unionArr.size() == 0 || unionArr.back() != arr1[i]) {
                unionArr.push_back(arr1[i]);
            }
            i++;
        }
        
        // Process remaining elements in arr2
        while(j < m) {
            if (unionArr.size() == 0 || unionArr.back() != arr2[j]) {
                unionArr.push_back(arr2[j]);
            }
            j++;
        }
        
        return unionArr;
    }
};
