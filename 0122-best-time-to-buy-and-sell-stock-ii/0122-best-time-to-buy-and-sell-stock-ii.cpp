// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>& prices,int k,int n,bool canBuy){
        if(k>=n)return 0;
        if(dp[k][canBuy]!=-1) return dp[k][canBuy];
        return dp[k][canBuy]=canBuy?
            max(
                solve(prices,k+1,n,false)-prices[k],    //buy
                solve(prices,k+1,n,true)                //keep the stock or buy and sell on same day
            ): 
            max(
                solve(prices,k+1,n,true)+prices[k],     //sell
                solve(prices,k+1,n,false)               //keep the stock or buy and sell on same day
            )
        ;
    }
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size(),vector<int>(2,-1));
        return solve(prices,0,prices.size(),true);
    }
};