
//T.C = 0(2^N)
//S.C = 0(N)

class Solution {
public:

    // Recursive function to generate all valid parentheses
    void Parenthesis(int n, int left, int right,
                     vector<string>& ans, string temp) {

        // Base case: when total brackets = 2*n,
        // store the current valid string
        if (left + right == 2 * n) {
            ans.push_back(temp);
            return;
        }

        //  Add '(' if we still can add left brackets
        if (left < n) {
            temp.push_back('(');
            Parenthesis(n, left + 1, right, ans, temp);
            temp.pop_back();   // backtrack
        }

        //  Add ')' only if it does not break validity
        // right brackets should never be more than left
        if (right < left) {
            temp.push_back(')');
            Parenthesis(n, left, right + 1, ans, temp);
            temp.pop_back();   // backtrack
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;   // store all valid combinations
        string temp;         // build one combination at a time

        // Start recursion with 0 '(' and 0 ')'
        Parenthesis(n, 0, 0, ans, temp);

        return ans;
    }
};