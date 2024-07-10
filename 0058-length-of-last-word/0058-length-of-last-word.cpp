// https://leetcode.com/problems/length-of-last-word

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length=0,i=s.length()-1;
        while(i>=0&&s[i--]==' ');
        while(i>=0&&s[i--]!=' ')length++;
        return length+1;
    }
};
