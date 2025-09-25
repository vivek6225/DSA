       // Optimal Approach
       // T.C =0(n)
       // s.C =0(k)
       class Solution {
public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        queue<int> q;
        vector<int> ans;
        int n = arr.size();

        // k-1 elements hai, push kar do agar negative hai
        for (int i = 0; i < k - 1; i++) {
            if (arr[i] < 0)
                q.push(i);
        }

        // ab window process karo
        for (int i = k - 1; i < n; i++) {
            if (arr[i] < 0)
                q.push(i);

          // agar queue ka front window ke bahar hai, to pop karo
            if (!q.empty() && q.front() <= i - k)
                q.pop();

      // agar queue empty hai to 0 push karo, otherwise first negative
            if (q.empty())
                ans.push_back(0);
            else
                ans.push_back(arr[q.front()]);
        }

        return ans;  
    }
};





//---------------------------------------------------------------
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