// https://leetcode.com/problems/set-mismatch

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size(),dup;
        vector<int>pos(n+1,0);
        for(int i=0;i<nums.size();i++)pos[nums[i]]++;
        return vector<int>({static_cast<int>(distance(pos.begin(),find(pos.begin()+1,pos.end(),2))),static_cast<int>(distance(pos.begin(),find(pos.begin()+1,pos.end(),0)))});
    }
};