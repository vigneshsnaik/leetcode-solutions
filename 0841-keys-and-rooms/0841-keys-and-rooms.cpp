// https://leetcode.com/problems/keys-and-rooms

#define OPEN true
class Solution {
public:
    vector<bool>state;
    void dfs(vector<vector<int>>& rooms,int room){
        if(state[room])return;
        state[room]=OPEN;
        for(int key:rooms[room])
            dfs(rooms,key);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        state.resize(n,false);
        dfs(rooms,0);
        return accumulate(state.begin(), state.end(), true, logical_and<bool>());
    }
};