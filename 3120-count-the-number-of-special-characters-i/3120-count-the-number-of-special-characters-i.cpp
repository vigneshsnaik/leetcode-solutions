// https://leetcode.com/problems/count-the-number-of-special-characters-i

class Solution {
public:
    int numberOfSpecialChars(string word) {
        bool a[26],A[26];
        for(int i=0;i<word.size();i++){
            if(word[i]>'Z') a[word[i]-'a']=true;
            else A[word[i]-'A']=true;
        }
        int res=0;
        for(int i=0;i<26;i++)if(a[i]&&A[i])res++;
        return res;
    }
};