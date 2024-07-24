class Solution {
public:
    int value(vector<int>& mapping, int n) {
        if (n < 10) {
            return mapping[n];
        }
        int res = 0, i = 0;
        while (n) {
            res += pow(10, i++) * mapping[n % 10];
            n /= 10;
        }
        return res;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int, int> values;
        for (int num : nums) {
            values[num] = value(mapping, num);
        }
        sort(nums.begin(), nums.end(),
             [&](int n1, int n2) { return values[n1] < values[n2]; });
        return nums;
    }
};