//s.c = 0(n)
//t.c =0(n)

class Solution {
  public:
    queue<int> reverseQueue(queue<int> &q) {
       
        stack<int>st;
    // Step 1: Push all queue elements into the stack
        while(!q.empty()){
            st.push(q.front());
            q.pop();
        }
      // Step 2: Push all stack elements back into the queue
        while(!st.empty()){
            
            q.push(st.top());
            st.pop();
        }
        return q;
    }    
};