// https://leetcode.com/problems/airplane-seat-assignment-probability

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
       return n==1?1.0:0.5;    
    }
};