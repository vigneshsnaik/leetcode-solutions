class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zero = 0, j = 0, res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                zero++;
            while (zero > k) {
                if (nums[j] == 0) {
                    zero--;
                }
                j++;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};