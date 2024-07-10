// https://leetcode.com/problems/sum-of-square-numbers

class Solution {
public:
    bool judgeSquareSum(int c) {
        int l=0,r=sqrt(c);
        while(l<=r){
            long long sumSq=(long long)l*l+(long long)r*r;
            if(sumSq>c)r--;
            else if(sumSq<c)l++;
            else return true;
        }
        return false;
    }
};