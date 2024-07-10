// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown

class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>& prices,int k,int n,bool canBuy){
        if(k>=n)return 0;
        if(dp[k][canBuy]!=-1) return dp[k][canBuy];
        return dp[k][canBuy]=canBuy?
            max({
                solve(prices,k+1,n,false)-prices[k],
                solve(prices,k+1,n,true),
                0
            }):
            max({
                solve(prices,k+2,n,true)+prices[k],
                solve(prices,k+1,n,false),
                0
            })
        ;
    }
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size(),vector<int>(2,-1));
        return solve(prices,0,prices.size(),true);
    }
};