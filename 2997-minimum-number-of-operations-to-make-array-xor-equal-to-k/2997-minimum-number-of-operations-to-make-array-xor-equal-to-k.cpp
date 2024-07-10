// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for(int i:nums)k^=i;
        int count=0;
        while(k){
            count+=k&1;
            k>>=1;
        }
        return count;
    }
};