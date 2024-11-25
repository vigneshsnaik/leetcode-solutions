class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target = "123450";
        vector<vector<int>> neighbours = {{1, 3}, {0, 2, 4}, {1, 5},
                                          {0, 4}, {3, 5, 1}, {4, 2}};
        set<string> visited;
        queue<string> q;
        string initial = "";
        for (auto r : board) {
            for (auto cell : r) {
                initial += cell + '0';
            }
        }
        q.push(initial);
        visited.insert(initial);
        int res = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string curr = q.front();
                q.pop();
                if (curr == target) {
                    return res;
                }
                int pos0 = curr.find('0');
                for (auto neighbour : neighbours[pos0]) {
                    string next = curr;
                    swap(next[pos0], next[neighbour]);
                    if (!visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
            res++;
        }
        return -1;
    }
};