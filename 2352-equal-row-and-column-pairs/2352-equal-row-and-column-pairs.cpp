// https://leetcode.com/problems/equal-row-and-column-pairs

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string,int>rows;
        unordered_map<string,int>cols;
        int count=0;
        auto vecToStr=[](const vector<int>&v){
            string s;
            for(int n:v)
                s+=to_string(n)+",";
            return s;
        };
        for(auto row:grid)
            rows[vecToStr(row)]++;
        for(int j=0;j<grid.size();++j) {
            vector<int> column;
            for (int i=0;i<grid.size();++i)
                column.push_back(grid[i][j]);
            string colStr=vecToStr(column);
            if (rows.find(colStr)!=rows.end())
                count+=rows[colStr];
        }
        return count;
    }
};