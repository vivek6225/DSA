 //Time Complexity: O(n)
 //Space Complexity: O(n) (in worst case, all brackets are opening) 

       \\LOGIC
     //.  If it’s an opening bracket ((, {, [), push it to the stack.
      //.If it’s a closing bracket:
      //.Check if the stack is empty (invalid case).
//.Check if it matches the top element of the stack. If yes, pop it. Else, return false.
//.At the end, if the stack is empty, the string is valid.

 
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            // opening
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }
            // closing
            else {
                if (st.empty()) {
                    return false;
                }

                char top = st.top();
                if ((top == '(' && s[i] == ')') ||
                    (top == '{' && s[i] == '}') ||
                    (top == '[' && s[i] == ']')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
