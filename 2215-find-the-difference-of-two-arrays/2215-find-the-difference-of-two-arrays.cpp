// https://leetcode.com/problems/find-the-difference-of-two-arrays

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int>isPresent(2001);
        vector<vector<int>>res(2,vector<int>(0));
        for(int num:nums1)
            isPresent[num+1000]|=0b01;
        for(int num:nums2)
            isPresent[num+1000]|=0b10;
        for(int i=0;i<2001;i++)
            if(isPresent[i]==0b01)res[0].push_back(i-1000);
            else if(isPresent[i]==0b10)res[1].push_back(i-1000);
        return res;
    }
};