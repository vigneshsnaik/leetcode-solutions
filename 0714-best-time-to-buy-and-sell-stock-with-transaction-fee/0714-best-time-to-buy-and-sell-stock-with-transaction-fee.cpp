// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int> prev(2),curr(2);
        prev[0]=prices[n-1];
        prev[1]=0;
        for(int i=n-2;i>=0;i--)
        {
            curr[1]=max(prev[1], prev[0]-prices[i]-fee);
            curr[0]=max(prev[0], prev[1]+prices[i]);
            prev=curr;
        }
        return prev[1];
    }
};