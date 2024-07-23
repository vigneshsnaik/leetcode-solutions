class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int count[201];
        for (int& num : nums) {
            count[num + 100]++;
        }
        sort(nums.begin(), nums.end(), [&](int n1, int n2) {
            if (count[n1 + 100] == count[n2 + 100])
                return n1 > n2;
            return count[n1 + 100] < count[n2 + 100];
        });
        return nums;
    }
};