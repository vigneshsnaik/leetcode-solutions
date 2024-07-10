// https://leetcode.com/problems/set-matrix-zeroes

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int>cols,rows;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    rows.insert(j);
                    cols.insert(i);
                }
            }
        }
        for(auto i: rows){
            for(int j=0;j<matrix.size();j++){
                matrix[j][i]=0;
            }
        }
        for(auto i: cols){
            for(int j=0;j<matrix[0].size();j++){
                matrix[i][j]=0;
            }
        }
    }
};