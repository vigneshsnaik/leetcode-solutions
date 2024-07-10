// https://leetcode.com/problems/find-the-highest-altitude

class Solution {
public:
    int largestAltitude(vector<int>& gains) {
        int height=0,maxHeight=0;
        for(int gain:gains)
            maxHeight=max(height+=gain,maxHeight);
        return maxHeight;
    }
};