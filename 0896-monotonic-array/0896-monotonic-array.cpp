// https://leetcode.com/problems/monotonic-array

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool flag=true;
        for(auto i=nums.begin()+1;i<nums.end();i++)
            if(*(i-1)>*i){
                flag=false;
                break;
            }
        if(flag)return true;
        for(auto i=nums.begin()+1;i<nums.end();i++)
            if(*(i-1)<*i)
                return false;
        return true;
    }
};