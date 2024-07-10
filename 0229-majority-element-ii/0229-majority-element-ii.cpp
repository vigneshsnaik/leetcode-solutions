// https://leetcode.com/problems/majority-element-ii

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0,count2=0,maj1=0,maj2=0;
        for(int num:nums)
            if(num==maj1)count1++;
            else if(num==maj2)count2++;
            else if(count1==0)maj1=num,count1++;
            else if(count2==0)maj2=num,count2++;
            else count1--,count2--;
        count1=count2=0;
        for (int num:nums)
            if(num==maj1)count1++;
            else if(num==maj2)count2++;
        int limit=nums.size()/3;
        if(count1>limit&&count2>limit)return{maj1,maj2};
        if(count1>limit)return{maj1};
        if(count2>limit)return{maj2};
        return {};
    }
};