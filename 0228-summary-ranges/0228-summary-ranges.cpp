// https://leetcode.com/problems/summary-ranges

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size()==0)return {};
        if (nums.size()==1)return {to_string(nums[0])};
        int start = nums[0], end = nums[0];
        vector<string> res;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] + 1 != nums[i]) {
                end = nums[i - 1];
                res.push_back(to_string(start) +
                              (start != end ? ("->" + to_string(end)) : ""));
                start = nums[i];
            }
        }
        end=nums[nums.size()-1];
        res.push_back(to_string(start) +
                      (start != end ? ("->" + to_string(end)) : ""));
        return res;
    }
};