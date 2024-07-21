class Solution {
public:
    vector<int>val={1,2};
    int helper(int n){
        if(val[n-1])return val[n-1];
        val[n-1]=helper(n-1)+helper(n-2);
        return val[n-1];
    }
    int climbStairs(int n) {
        val.resize(n,0);
        return helper(n);
    }
};