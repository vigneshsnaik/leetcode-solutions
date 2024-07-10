// https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<string>>grid(3,vector<string>(3,"."));
        for(int i=0;i<moves.size();++i)
            grid[moves[i][0]][moves[i][1]]=(i%2==0)?"A":"B";
        for(int i=0; i<3;++i) {
            if (grid[i][0]==grid[i][1]&&grid[i][1]==grid[i][2]&&grid[i][0]!=".")return grid[i][0];
            if (grid[0][i]==grid[1][i]&&grid[1][i]==grid[2][i]&&grid[0][i]!=".")return grid[0][i];
        }
        if (grid[0][0]==grid[1][1]&&grid[1][1]==grid[2][2]&&grid[0][0]!=".")return grid[0][0];
        if (grid[0][2]==grid[1][1]&&grid[1][1]==grid[2][0]&&grid[0][2]!=".")return grid[0][2];
        return moves.size()==9?"Draw":"Pending";
    }
};
