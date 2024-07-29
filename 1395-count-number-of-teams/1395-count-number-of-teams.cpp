class Solution {
public:
    int numTeams(vector<int>& rating) {
        int count = 0;
        for (auto i = rating.begin(); i != rating.end(); i++) {
            for (auto j = i; j != rating.end(); j++) {
                for (auto k = j; k != rating.end(); k++) {
                    if ((*i < *j and *j < *k) or (*i > *j and *j > *k)) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};