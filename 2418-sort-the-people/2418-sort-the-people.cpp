class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> pairs;
        for (int i = 0; i < names.size(); i++) {
            pairs.push_back({heights[i], names[i]});
        }
        sort(pairs.begin(), pairs.end(),
             [](auto p1, auto p2) { return p1.first > p2.first; });
        for (int i = 0; i < names.size(); i++) {
            names[i] = pairs[i].second;
        }
        return names;
    }
};