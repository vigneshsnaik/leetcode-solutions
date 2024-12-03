class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int prevSpace = 0;
        string res;
        for (int currSpace : spaces) {
            res += s.substr(prevSpace, currSpace - prevSpace) + " ";
            prevSpace = currSpace;
        }
        res += s.substr(prevSpace);
        return res;
    }
};