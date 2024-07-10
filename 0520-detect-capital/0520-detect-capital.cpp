// https://leetcode.com/problems/detect-capital

class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() == 1)
            return true;
        int count = 0;
        for (int i = 0; i < word.size(); i++)
            if (isupper(word[i]))
                count++;
        if (count == 1 && isupper(word[0]))
            return true;
        if (count == 0 || count == word.size())
            return true;
        else
            return false;
    }
};