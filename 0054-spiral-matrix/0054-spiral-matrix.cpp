class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m=matrix.size(),n=matrix[0].size(),t=0,b=m-1,l=0,r=n-1;
        while(t<=b&&l<=r){
            for(int j=l;j<=r;++j)res.push_back(matrix[t][j]);
            t++;
            for(int i=t;i<=b;++i)res.push_back(matrix[i][r]);
            r--;
            if(t<=b)for(int j=r;j>=l;--j)res.push_back(matrix[b][j]);
            b--;
            if(l<=r)for(int i=b;i>=t;--i)res.push_back(matrix[i][l]);
            l++;
        }
        return res;
    }
};
