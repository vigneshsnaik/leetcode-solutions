// https://leetcode.com/problems/partition-labels

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<vector<int>> ranges(26, vector<int>(2, -1));
        for (int i = 0; i < s.length(); i++) {
            if (ranges[s[i] - 'a'][0] == -1) {
                ranges[s[i] - 'a'][0] = ranges[s[i] - 'a'][1] = i;
            } else {
                ranges[s[i] - 'a'][1] = i;
            }
        }
        sort(ranges.begin(), ranges.end());
        vector<vector<int>> mergedRanges;
        for (auto& range : ranges) {
            if (range[0] == -1) {
                continue;
            } else if (mergedRanges.empty() ||
                       mergedRanges.back()[1] < range[0]) {
                mergedRanges.push_back(range);
            } else {
                mergedRanges.back()[1] = max(mergedRanges.back()[1], range[1]);
            }
        }
        vector<int> res;
        for (auto range : mergedRanges) {
            res.push_back(range[1] - range[0] + 1);
        }
        return res;
    }
};