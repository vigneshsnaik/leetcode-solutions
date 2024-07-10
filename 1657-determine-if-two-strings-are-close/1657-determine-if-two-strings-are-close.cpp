// https://leetcode.com/problems/determine-if-two-strings-are-close

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int>freq1(26, 0);
        vector<int>freq2(26, 0);
        for (char ch:word1)
            freq1[ch-'a']++;
        for (char ch:word2)
            freq2[ch-'a']++;
        for(int i=0;i<26;i++)
            if((freq1[i]&&!freq2[i])||(!freq1[i]&&freq2[i]))return false;
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        for(int i=0;i<26;i++)
            if(freq1[i]!=freq2[i])return false;
        return true;
    }
};