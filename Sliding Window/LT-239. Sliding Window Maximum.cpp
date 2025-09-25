                
                      // Optimal Approach
       //T.C = O(n)
       //S.C = O(n)
    class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       deque<int>d;
       vector<int>ans;
       int  n = nums.size();
       // k-1 elements ko traverse karo
       for(int  i = 0; i< k-1;i++){
        if(d.empty())
        d.push_back(i);
        else{

  // Remove all smaller elements from the back of deque
        while(!d.empty() && nums[i] > nums[d.back()])
           d.pop_back();
      // Add current index to deque
           d.push_back(i);
        }
       }
        // Process the rest of the elements
        for(int i = k-1; i<n; i++){
   // remove smallest element from back
            while(!d.empty() && nums[i] > nums[d.back()])
                d.pop_back();
                
            // Add current index to deque
                d.push_back(i);
            // if front element is outside the window, pop it
            if(d.front() <= i-k)
            d.pop_front(); 
             // find ans
             ans.push_back(nums[d.front()]);
        }
         return ans;
    }
};
//---------------------------------------------------------------------
                       //Brute force Approach
        //t.c = 0(n*k)
        //s.c = 0(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        int n = nums.size();

         // Iterate over each possible window starting index
        for(int i = 0; i<= n-k;i++){
          int   total = INT_MIN;// Initialize the maximum value in the window as very small
            
            // Traverse the current window of size k
          for(int j = i; j < i+k; j++){
            total  = max(total,nums[j]);// Update maximum element in the current window
          }
             // Store the maximum of the current window
          ans.push_back(total);
        }
        return ans; // Return the list of maximums for all windows
    }
};