// https://leetcode.com/problems/subsets

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int total=pow(2,nums.size());
        for(int i=0;i<total;i++){
            vector <int> temp;
            for(int j=0;j<nums.size();j++){
                if(i>>j&1)temp.push_back(nums[j]);
            }
            res.push_back(temp);
        }
        return res;
    }
};