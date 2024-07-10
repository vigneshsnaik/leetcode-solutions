// https://leetcode.com/problems/find-the-pivot-integer

class Solution {
public:
    int pivotInteger(int n) {
        int x=sqrt((n*n+n)/2);
        return x==sqrt((n*n+n)/2)?x:-1;
    }
};