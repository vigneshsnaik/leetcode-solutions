// https://leetcode.com/problems/longest-common-subsequence

class Solution {
public:
    vector<vector<int>>dp;
    string s1,s2;
    int solve(int i1,int i2){
        if(!s1[i1]||!s2[i2])return 0;
        if(s1[i1]==s2[i2])return solve(i1+1,i2+1)+1;
        if(dp[i1][i2]==-1)return dp[i1][i2]=max(solve(i1+1,i2),solve(i1,i2+1));
        return dp[i1][i2];
    }
    int longestCommonSubsequence(string text1, string text2) {
        s1=text1,s2=text2;
        dp.resize(text1.size(),vector<int>(text2.size(),-1));
        return solve(0,0);
    }
};