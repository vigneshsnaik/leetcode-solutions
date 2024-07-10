// https://leetcode.com/problems/unique-paths

class Solution {
public:
    vector<vector<int>>dp;
    int limitX,limitY;
    int solve(int x,int y){
        if(x==limitX||y==limitY)return 0;
        if(dp[x][y])return dp[x][y];
        dp[x][y]=solve(x+1,y)+solve(x,y+1);
        return dp[x][y];
    }
    int uniquePaths(int m, int n) {
        limitX=m,limitY=n;
        dp.resize(m,vector<int>(n));
        dp[m-1][n-1]=1;
        return solve(0,0);
    }
};