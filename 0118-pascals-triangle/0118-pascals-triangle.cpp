// https://leetcode.com/problems/pascals-triangle

class Solution {
public:
    vector<vector<int>> generate(int n){
        if(n==0)return {};
        else if(n==1)return {{1}};
        else {
            vector<vector<int>>triangle=generate(n-1);
            vector<int>new_row(n,1);
            for(int i=1;i<n-1;++i)new_row[i]=triangle[n-2][i-1]+triangle[n-2][i];
            triangle.push_back(new_row);
            return triangle;
        }
    }
};