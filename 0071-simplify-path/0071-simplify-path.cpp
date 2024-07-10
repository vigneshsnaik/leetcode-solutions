// https://leetcode.com/problems/simplify-path

class Solution {
public:
    string simplifyPath(string path) {
        istringstream iss(path);
        stack<string> st;
        string dir;
        while (getline(iss, dir, '/')) {
            if (!dir.empty()) {
                if (dir == ".") {
                    continue;
                } else if (dir == "..") {
                    if (!st.empty()) {
                        st.pop();
                    }
                } else {
                    st.push(dir);
                }
            }
        }
        string res;
        while (!st.empty()) {
            res = "/" + st.top() + res;
            st.pop();
        }
        return !res.empty() ? res : "/";
    }
};