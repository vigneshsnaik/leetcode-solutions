// https://leetcode.com/problems/find-common-characters

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<vector<int>> array(words.size(), vector<int>(26, 0)); 
        vector<string>res;
        for(int i=0;i<words.size();i++)
            for(char ch:words[i])
                array[i][ch-'a']++;
        for(int j=0;j<26;j++){
            int MIN=100;
            for(int i=0;i<words.size();i++)
                MIN=min(MIN,array[i][j]);
            for(int i=0;i<MIN;i++)
                res.push_back(string(1,'a'+j));
        }
        return res;
    }
};