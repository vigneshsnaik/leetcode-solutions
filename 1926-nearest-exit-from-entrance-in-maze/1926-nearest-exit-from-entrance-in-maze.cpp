// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size(),n=maze[0].size(),entrance_row=entrance[0],entrance_col=entrance[1];
        vector<pair<int,int>>directions={{-1,0},{1,0},{0,-1},{0,1}}; 
        queue<pair<int,int>>q;
        q.push({entrance_row, entrance_col});
        maze[entrance_row][entrance_col] = '-';
        int steps=0;
        while (!q.empty()){
                int size = q.size();
                while (size--) {
                auto curr=q.front();
                q.pop();
                int row=curr.first,col=curr.second;
                for(auto &dir:directions){
                    int nr=row+dir.first,nc=col+dir.second;
                    if(nr>=0&&nr<m&&nc>=0&&nc<n){
                        if(maze[nr][nc]=='.'&&(nr==0||nr==m-1||nc==0||nc==n-1))return steps + 1;
                        else if(maze[nr][nc]=='.'){
                            maze[nr][nc]='-';
                            q.push({nr, nc});
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};