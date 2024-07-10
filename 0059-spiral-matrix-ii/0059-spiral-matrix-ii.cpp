// https://leetcode.com/problems/spiral-matrix-ii

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int t=0,b=n-1,l=0,r=n-1,k=1;
        while(k<=n*n){
            for(int j=l;j<=r;++j)matrix[t][j]=k++;
            t++;
            for(int i=t;i<=b;++i)matrix[i][r]=k++;
            r--;
            for(int j=r;j>=l;--j)matrix[b][j]=k++;
            b--;
            for(int i=b;i>=t;--i)matrix[i][l]=k++;
            l++;
        }
        return matrix;
    }
};