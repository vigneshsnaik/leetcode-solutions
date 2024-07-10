// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt=0;
        for(int i=0;i<32;i++){
            bool A=a&(1<<i),B=b&(1<<i),C=c&(1<<i);
            if (C&&!(A||B))cnt++;
            else if(!C&&(A&&B))cnt+=2;
            else if(!C&&(A||B))cnt++;
        }
        return cnt;
    }
};