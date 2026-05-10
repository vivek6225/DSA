        
//--------------------Optimal Approach----------------

// T.c = 0(n)
//s.c = 0(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();

        // i -> points to last unique element
        // j -> traverses the array
        int i = 0, j = 1;

        while(j < n) {

            // If new unique element found
            if(nums[i] != nums[j]) {

                // Move i to next position
                i++;

                // Overwrite duplicate position
                // with new unique element
                nums[i] = nums[j];
            }

            // Move j forward
            j++;
        }

        //   Number of unique elements
        return i + 1;
    }
};
//-------------------Better Approach----------------
   // What is a set?
// A set in C++ is a container from the Standard Template Library (STL).

// (i) Stores unique elements (no duplicates).
// (ii) Elements are always stored in sorted order (ascending by default).
// (iii) Internally implemented using a Balanced BST (Red-Black Tree).

// Time Complexity  : O(n log n)
// Space Complexity : O(n) 

      class Solution {
       public:
           int removeDuplicates(vector<int>& nums) {
                set<int> st;  // stores unique elements (sorted automatically)
        
              // Step 1: insert all elements into set
             for (int i = 0; i < nums.size(); i++) {
                  st.insert(nums[i]);  // each insert = O(log n),You are inserting n elements.,Total = n × log n → O(n log n)
             }

               // Step 2: copy set elements back to nums
                    int index = 0;
                   for (auto it : st) {
                     nums[index] = it;
                     index++;
                 }

             // Step 3: return new length (number of unique elements)
               return index;
    }
};
//-------------------Brute Force Approach----------------

// Time Complexity	= O(n²) 
// Space Complexity= O(n)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Get the size of the input array
        int n = nums.size();

        // Temporary vector to store unique elements
        vector<int> temp;

        // Traverse through each element of the original array
        for(int i = 0; i < n; i++) {

            // Flag to check if current element already exists in temp
            bool found = false;

            // Check in temp vector if nums[i] is already present
            for(int j = 0; j < temp.size(); j++) {
                if(nums[i] == temp[j]) {
                    found = true;   // Duplicate found
                    break;          // No need to check further
                }
            }

            // If element is not found in temp, add it (unique element)
            if(!found) {
                temp.push_back(nums[i]);
            }
        }

        // Copy unique elements back to original array
        for(int i = 0; i < temp.size(); i++) {
            nums[i] = temp[i];
        }

        // Return the number of unique elements
        return temp.size();
    }
};