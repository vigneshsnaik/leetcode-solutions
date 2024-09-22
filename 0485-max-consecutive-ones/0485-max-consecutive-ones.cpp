class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int c = 0;
        for (int num : nums) {
            if (num) {
                c++;
                res = max(res, c);
            } else {
                c = 0;
            }
        }
        return res;
    }
};