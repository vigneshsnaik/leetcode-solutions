// https://leetcode.com/problems/minimum-increment-to-make-array-unique

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res=0;
        for(auto i=nums.begin()+1;i!=nums.end();i++)
            if(*i<=*(i-1)){
                res+=*(i-1)-*i+1;
                *i=*(i-1)+1;
            }
        return res;
    }
};