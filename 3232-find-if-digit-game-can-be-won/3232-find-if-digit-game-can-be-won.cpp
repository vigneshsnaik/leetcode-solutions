class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int total = 0, one = 0, two = 0;
        for (int& num : nums) {
            total += num;
            one += num < 10 ? num : 0;
            two += num < 100 && num > 9 ? num : 0;
        }
        return one > total - one or two > total - two;
    }
};