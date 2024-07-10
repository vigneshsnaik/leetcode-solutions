// https://leetcode.com/problems/pass-the-pillow

class Solution {
public:
    int passThePillow(int n, int time) {
        return (time / (n - 1)) % 2 ? n - time % (n - 1) : time % (n - 1) + 1;
    }
};