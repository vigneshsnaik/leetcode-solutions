// https://leetcode.com/problems/daily-temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        vector<int> stack;
        for (int i=temperatures.size()-1;i >= 0;--i) {
            while(!stack.empty()&&temperatures[i]>=temperatures[stack.back()])
                stack.pop_back();
            if(!stack.empty())result[i]=stack.back()-i;
            stack.push_back(i);
        }
        return result;
    }
};

