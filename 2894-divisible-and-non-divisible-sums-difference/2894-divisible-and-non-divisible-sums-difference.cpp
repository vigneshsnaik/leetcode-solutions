// https://leetcode.com/problems/divisible-and-non-divisible-sums-difference

class Solution {
public:
    int differenceOfSums(int n, int m) {
        return (n*n+n)/2-((n/m)*(n/m)+(n/m))*m;
    }
};