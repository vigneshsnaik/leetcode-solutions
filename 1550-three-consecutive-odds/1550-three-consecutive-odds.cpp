// https://leetcode.com/problems/three-consecutive-odds

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt = 0;
        for (const int& n : arr) {
            if (n % 2)
                cnt++;
            else
                cnt = 0;
            if (cnt == 3)
                return true;
        }
        return false;
    }
};