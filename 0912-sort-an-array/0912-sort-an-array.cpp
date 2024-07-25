class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int> heap;
        for (int& num : nums) {
            heap.push(num);
        }
        int i = nums.size();
        while (!heap.empty()) {
            nums[--i] = heap.top();
            heap.pop();
        }
        return nums;
    }
};