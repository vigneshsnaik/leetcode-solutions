class Solution {
public:
    int countSeniors(vector<string>& details) {
        return count_if(details.begin(), details.end(), [](const string& str) {
            return str[11] > '6' or (str[11] == '6' and str[12] > '0');
        });
    }
};