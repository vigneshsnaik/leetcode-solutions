class Solution {
public:
    vector<string> res;
    void solve(int n, int open, int close, string s) {
        if (open == n and close == n) {
            res.push_back(s);
            return;
        }
        if (open < n) {
            solve(n, open + 1, close, s + "(");
        }
        if (close < open) {
            solve(n, open, close + 1, s + ")");
        }
    }
    vector<string> generateParenthesis(int n) {
        solve(n, 0, 0, "");
        return res;
    }
};