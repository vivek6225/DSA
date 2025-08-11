           //T.C = 0(N)
           //S.C = 0(K)
//.Use a stack to reverse the first k elements.
//.Pop first k elements from queue and push int stack.
//.Pop from stack and push back into queue (reversed order).
//.Rotate the remaining elements to maintain their original order.

class Solution {
  public:
          
    queue<int> reverseFirstK(queue<int> q, int k) {
         //Boundary check for k (must be valid).
        if (k <= 0 || k > q.size()) return q;
        
        stack<int> st;
        for (int i = 0; i < k; i++) {
            st.push(q.front());
            q.pop();
        }
        
        while (!st.empty()) {
            q.push(st.top());
            st.pop();
        }
        
        int n = q.size() - k; // ✅ only rotate the rest
        while (n--) {
            q.push(q.front());
            q.pop();
        }
        
        return q;
    }
};
