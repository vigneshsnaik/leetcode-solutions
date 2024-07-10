// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

class Solution {
public:
    int strStr(string haystack, string needle) {
        const int lHaystack=haystack.length(),lNeedle=needle.length();
        for(int i=0;i<=lHaystack-lNeedle;i++)
            if(haystack.substr(i,lNeedle)==needle)
                return i;
        return -1;
    }
};