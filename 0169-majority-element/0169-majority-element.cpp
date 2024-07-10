// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj=0,count=0;
        for(int num:nums)
            if(num==maj)count++;
            else if(count==0)maj=num;
            else count--;
        return maj;
    }
};