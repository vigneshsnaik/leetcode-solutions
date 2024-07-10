// https://leetcode.com/problems/rotting-oranges

#define fresh 1
#define rotten 2

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),time=-1,nFresh=0,nRotten=0;
        queue<pair<int,int>>q;
        vector<pair<int,int>>neighbours={{0,1},{1,0},{0,-1},{-1,0}};
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==fresh)nFresh++;
                else if(grid[i][j]==rotten){
                    nRotten++;
                    q.push({i,j});
                }
        if(!nRotten&&!nFresh)return 0;
        if(!nRotten&&nFresh)return -1;
        while(!q.empty()){
            time++;
            int size=q.size();
            while(size--){
                auto [x,y]=q.front();
                for(auto[dx,dy]:neighbours){
                    int X=x+dx;
                    int Y=y+dy;
                    if(X>=0&&X<m&&Y>=0&&Y<n&&grid[X][Y]==fresh){
                        q.push({X,Y});
                        grid[X][Y]=rotten;
                        nFresh--;
                    }
                }
                q.pop();
            }
        }
        return nFresh?-1:time;
    }
};