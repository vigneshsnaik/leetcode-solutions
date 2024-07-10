// https://leetcode.com/problems/calculate-money-in-leetcode-bank

class Solution {
public:
    int totalMoney(int n) {
        return (n/7)*28+(n/7-1)*(n/7)*7/2+n%7*(n%7+1)/2+(n/7)*(n%7);
    }
};