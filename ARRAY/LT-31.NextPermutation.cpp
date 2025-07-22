     
   
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      //        using STL  T.C = 0(N), S.C = 0(1)
     //   next_permutation(nums.begin(),nums.end());
                 
        int pivot = -1;
        int n = nums.size();  //  T.C = 0(N), S.C = 0(1)
       // step 1.find the first decresing element from the right  // t.c=0(n)
        for(int i = n-2; i>= 0; i--){
            if(nums[i] < nums[i+1]){
            pivot = i;
            break;
        } 
        }
        //  if no element is found reverse the entire array
        if(pivot == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
        
// step 2. find next largest number to swap with nums[index] // t.c=0(n) 
         for(int  i = n-1; i>pivot; i--){
            if(nums[i] > nums[pivot]){
            swap(nums[i],nums[pivot]);
            break;
         } 
         }
          //step 3. reverse the element after swap // t.c=0(n)
          reverse(nums.begin() + pivot+1,nums.end());
          return;


        
    }
};