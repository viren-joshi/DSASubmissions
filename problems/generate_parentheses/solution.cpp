class Solution {
public:

    void solution(string op, int open, int close, vector<string>& ans, int n) {
        if(open == n && close == n) {
            ans.push_back(op);
            return;
        }
        if(open < n) {
            // Then we only have one option which is to add '('
            op.push_back('(');
            solution(op, open + 1, close, ans, n);
            op.pop_back();
        }
        if (close < open) {
            op.push_back(')');
            solution(op, open ,close+1, ans, n);
            op.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        int open = 0;
        int close = 0;
        vector<string> ans;
        string op = "";
        solution(op, open, close, ans, n);
        return ans;
    }
};