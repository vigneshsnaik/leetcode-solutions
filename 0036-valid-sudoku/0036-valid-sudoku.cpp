// https://leetcode.com/problems/valid-sudoku

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int col=0;col<9;col++){
        vector<bool>ispresent(9,false);
            for(int i=0;i<9;i++){
                if(board[i][col]=='.')continue;
                else if(ispresent[board[i][col]-'1'])return false;
                else ispresent[board[i][col]-'1']=true;
            }
        }
        for(int row=0;row<9;row++){
            vector<bool>ispresent(9,false);
            for(int i=0;i<9;i++){
                if(board[row][i]=='.')continue;
                else if(ispresent[board[row][i]-'1'])return false;
                else ispresent[board[row][i]-'1']=true;
            }
        }
        vector<pair<int,int>>boxes={{1,1},{1,4},{1,7},{4,1},{4,4},{4,7},{7,1},{7,4},{7,7}};
        for(auto &[X,Y]:boxes){
            vector<bool>ispresent(9,false);
            for(int x=-1;x<=1;x++){
                for(int y=-1;y<=1;y++){
                    if(board[X+x][Y+y]=='.')continue;
                    else if(ispresent[board[X+x][Y+y]-'1'])return false;
                    else ispresent[board[X+x][Y+y]-'1']=true;
                }
            }
        }
        return true;
    }
};