class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int MAX, pdt;
        MAX = pdt = nums[0] * nums[1] * nums[2];
        for (int i = 3; i < nums.size(); i++) {
            pdt *= nums[i] / nums[i - 3];
            MAX = max(MAX, pdt);
        }
        return MAX;
    }
};