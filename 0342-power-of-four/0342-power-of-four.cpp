// https://leetcode.com/problems/power-of-four

class Solution {
public:
    bool isPowerOfFour(int n) {
        return n>0&&(n&(n-1))==0&&(n&0b01010101010101010101010101010101)!= 0;
    }
};