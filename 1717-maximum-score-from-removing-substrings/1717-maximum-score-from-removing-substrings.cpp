class Solution {
public:
    int maximumGain(string s, int x, int y) {
        char sub0 = 'a', sub1 = 'b';
        if (x < y) {
            swap(x, y);
            swap(sub0, sub1);
        }
        int points = 0;
        string st;
        for (char c : s) {
            if (!st.empty() && st.back() == sub0 && c == sub1) {
                st.pop_back();
                points += x;
            } else {
                st.push_back(c);
            }
        }
        s = st;
        st = "";
        for (char c : s) {
            if (!st.empty() && st.back() == sub1 && c == sub0) {
                st.pop_back();
                points += y;
            } else {
                st.push_back(c);
            }
        }
        return points;
    }
};
