// https://leetcode.com/problems/valid-perfect-square

class Solution {
public:
    int mySqrt(int x) {
        if(x<=1) return x;
        int high =x,low=1;
        while (high>=low){
            int mid=low+(high-low)/2;
            if(mid>x/mid)high=mid-1;
            else if(mid<x/mid)low=mid+1;
            else return mid;
        }
        return high;
    }
    bool isPerfectSquare(int num) {
        int x=mySqrt(num);
        return x*x==num;
    }
};