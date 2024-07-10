// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        const vector<string>pad={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(digits.empty())return{};
        vector<string>res={""};
        for(char digit:digits){
            vector<string>tmp;
            for(char letter:pad[digit-'0'])
                for(string s:res)
                    tmp.push_back(s+letter);
            res=tmp;
        }
        return res;
    }
};