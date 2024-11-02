class Solution {
public:
    string makeFancyString(string s) {
        string res = "";
        int cnt = 0;
        for (char c : s) {
            if (cnt == 0) {
                res.push_back(c);
                cnt++;
            } else if (c == res.back()) {
                cnt++;
                if (cnt < 3) {
                    res.push_back(c);
                }
            } else {
                cnt = 1;
                res.push_back(c);
            }
        }
        return res;
    }
};