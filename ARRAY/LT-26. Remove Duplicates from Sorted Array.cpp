        
          // Optimal Approach
          // T.c = 0(n)
          //s.c = 0(1)

 class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
       
       int i = 0; // slow pointer → last unique element
         for (int j = 1; j < nums.size(); j++) { // fast pointer
                if (nums[i] != nums[j]) {
                        nums[i+1] = nums[j]; // put new unique element next to last unique
                            i++;       // move slow pointer forward
    }
}
return i + 1; // length of unique elements
    }
};
//-----------------------------------------------------------------------------------------
     //What is a set?
     //  A set in C++ is a container from the Standard Template Library (STL).
               //(i) Stores unique elements (no duplicates).
              //(ii)  Elements are always stored in sorted order (ascending by default).
              //(iii) Based on a balanced BST (Red-Black Tree) internally.      
           
             //Brute Force Approach
            // T.C = 0(n log n)
            //S.C = 0(n) 

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