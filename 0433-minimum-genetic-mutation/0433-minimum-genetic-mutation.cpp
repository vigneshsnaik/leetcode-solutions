class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        vector<char> chars = {'A', 'G', 'T', 'C'};
        unordered_set<string> list;
        for (string gene : bank) {
            list.insert(gene);
        }
        queue<string> q;
        q.push(startGene);
        int res = 1;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                string curr = q.front();
                q.pop();
                if (curr == endGene) {
                    return res-1;
                }
                list.erase(curr);
                for (int j = 0; j < curr.size(); j++) {
                    char tmp = curr[j];
                    for (char c : chars) {
                        curr[j] = c;
                        if (list.find(curr) != list.end()) {
                            q.push(curr);
                        }
                    }
                    curr[j] = tmp;
                }
            }
            res++;
        }
        return -1;
    }
};