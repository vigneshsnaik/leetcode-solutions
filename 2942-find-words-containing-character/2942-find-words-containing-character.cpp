// https://leetcode.com/problems/find-words-containing-character

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;
        for(int i=0;i<words.size();i++)
            for(char c:words[i])
                if(x==c){
                    res.push_back(i);
                    break;
                }
        return res;
    }
};