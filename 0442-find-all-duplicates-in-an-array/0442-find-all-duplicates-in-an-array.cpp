// https://leetcode.com/problems/find-all-duplicates-in-an-array

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
    vector<int> duplicates;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[abs(nums[i]) - 1] < 0) {
                duplicates.push_back(abs(nums[i]));
            } else {
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
            }
        }
        return duplicates;
    }
};