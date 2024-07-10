// https://leetcode.com/problems/sign-of-the-product-of-an-array

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int cnt=0;
        for(int x:nums){
            if(!x)return 0;
            if(x<0)cnt++;
        }
        return (cnt%2)?-1:1;
    }
};