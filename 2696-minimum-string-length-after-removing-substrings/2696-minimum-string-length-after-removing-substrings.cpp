class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for (char c : s) {
            if (!st.empty()) {
                if (st.top() == 'A' and c == 'B') {
                    st.pop();
                } else if (st.top() == 'C' and c == 'D') {
                    st.pop();
                } else {
                    st.push(c);
                }
            } else {
                st.push(c);
            }
        }
        return st.size();
    }
};
