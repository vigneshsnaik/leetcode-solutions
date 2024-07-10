// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)return 0;
        int min_value=prices[0];
        int max_diff=0;
        for(int i=1;i<prices.size();++i) {
            if(prices[i]>min_value){
                if(prices[i]-min_value>max_diff)max_diff=prices[i]-min_value;
            }
            else min_value = prices[i];
        }
        return max_diff;
    }
};