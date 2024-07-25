class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int j = 0;
        for (int i = 0; i < trainers.size() && j < players.size(); ++i)
            j += players[j] <= trainers[i];
        return j;
    }
};