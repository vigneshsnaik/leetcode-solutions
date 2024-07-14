class NumArray {
public:
    vector<int> sum = {0};
    NumArray(vector<int>& nums) {
        for (int& num : nums) {
            sum.push_back(sum.back() + num);
        }
    }

    int sumRange(int left, int right) { return sum[right + 1] - sum[left]; }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */