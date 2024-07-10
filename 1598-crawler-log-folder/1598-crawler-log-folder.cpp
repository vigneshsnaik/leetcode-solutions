class Solution {
public:
    int minOperations(vector<string>& logs) {
        int res = 0;
        for (string log : logs) {
            if (log == "../") {
                if (res)
                    res--;
            } else if (log == "./") {
                continue;
            } else {
                res++;
            }
        }
        return res;
    }
};