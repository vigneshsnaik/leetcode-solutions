class Solution {
public:
    vector<int> getNSL(vector<int>& heights) {
        vector<int> NSL(heights.size());
        stack<int> s;
        for (int i = 0; i < heights.size(); i++) {
            while (!s.empty() && heights[i] <= heights[s.top()])
                s.pop();
            if (s.empty())
                NSL[i] = 0;
            else
                NSL[i] = s.top();
            s.push(i);
        }
        return NSL;
    }
    vector<int> getNSR(vector<int>& heights) {
        vector<int> NSR(heights.size());
        stack<int> s;
        for (int i = heights.size() - 1; i >= 0; --i) {
            while (!s.empty() && heights[i] <= heights[s.top()])
                s.pop();
            if (s.empty())
                NSR[i] = heights.size();
            else
                NSR[i] = s.top();
            s.push(i);
        }
        return NSR;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> NSR = getNSR(heights);
        vector<int> NSL = getNSL(heights);
        int maxi = 0;
        for (int i = 0; i < heights.size(); i++) {
            maxi = max(maxi, (NSR[i] - NSL[i] - 1) * heights[i]);
        }
        return maxi;
    }
};