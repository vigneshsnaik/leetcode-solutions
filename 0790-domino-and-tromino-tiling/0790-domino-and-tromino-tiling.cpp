// https://leetcode.com/problems/domino-and-tromino-tiling

#define mod 1000000007
class Solution {
public:
    vector<int>dp{0,1,2,5};
    int helper(int n){
        if(dp[n])return dp[n];
        dp[n]=((long)helper(n-3)+(long)2*helper(n-1))%mod;
        return dp[n]; 
    }
    int numTilings(int n) {
        dp.resize(n+1,0);
        return helper(n);
    }
};