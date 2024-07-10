// https://leetcode.com/problems/shuffle-an-array

class Solution {
public:
    vector<int> original;
    int n;
    Solution(vector<int>& nums) {
        original = nums;
        n = original.size();
    }

    vector<int> reset() { return original; }

    vector<int> shuffle() {
        vector<int> shuffled(original);
        for (int i = 0; i < n; i++) {
            int pos = rand() % (n - i);
            swap(shuffled[i + pos], shuffled[i]);
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */