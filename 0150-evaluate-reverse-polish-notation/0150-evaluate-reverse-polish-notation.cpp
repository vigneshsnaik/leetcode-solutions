// https://leetcode.com/problems/evaluate-reverse-polish-notation

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int(int, int)>> map = {
            {"+", [](int a, int b) { return a + b; }},
            {"-", [](int a, int b) { return a - b; }},
            {"*", [](int a, int b) { return a * b; }},
            {"/", [](int a, int b) { return a / b; }}};
        stack<int> st;
        for (string token : tokens) {
            if (!map.count(token))
                st.push(stoi(token));
            else {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(map[token](a, b));
            }
        }
        return st.top();
    }
};