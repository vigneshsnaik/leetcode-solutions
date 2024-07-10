// https://leetcode.com/problems/spiral-matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size()-1,m=matrix[0].size()-1;
        vector<int>res;
        int l=0,r=m,t=0,b=n;
        while(t<=b&&l<=r){
            for(int i=l;i<=r;i++)res.push_back(matrix[t][i]);
            t++;
            for(int i=t;i<=b;i++)res.push_back(matrix[i][r]);
            r--;
            if(t<=b)for(int i=r;i>=l;i--)res.push_back(matrix[b][i]);
            b--;
            if(l<=r)for(int i=b;i>=t;i--)res.push_back(matrix[i][l]);
            l++;
        }
        return res;
    }
};