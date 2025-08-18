//Better Approach
// T.C = 0(n*k)
// S.C = 0(k)
class Solution {
  public:
   int display(queue<int>q){
       while(!q.empty()){
           if(q.front() < 0)
               return q.front();  // first negative found
               q.pop();
       }
       return 0;  // if no negative in window
   }
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        queue<int>q;
        int  n = arr.size();
        // store first (k-1) elements
        for(int  i = 0; i<k-1; i++)
            q.push(arr[i]);
            vector<int>ans;
               // process each window
            for(int i = k-1; i<n;i++){
                q.push(arr[i]);
                ans.push_back(display(q)); // find first negative in window
                q.pop();
            }
            return ans;
    }
};