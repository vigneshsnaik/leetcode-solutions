// https://leetcode.com/problems/water-bottles

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange,int empty=0)
    { 
        if ((numBottles+empty)/numExchange == 0 )return numBottles;
        return numBottles+numWaterBottles((numBottles+empty)/numExchange,numExchange,(numBottles+empty)%numExchange);
    }
};