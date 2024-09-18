class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strNums;
        for (int num : nums) {
            strNums.push_back(to_string(num));
        }
        sort(strNums.begin(), strNums.end(), [](const string& a, const string& b) {
            return (b + a) < (a + b);
        });
        if (strNums[0] == "0") {
            return "0";
        }
        string res;
        for (const string& num : strNums) {
            res += num;
        }
        return res;
    }
};