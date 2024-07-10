// https://leetcode.com/problems/reverse-vowels-of-a-string

class Solution {
public:
    char isVowel(char c){
        return(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U');
    }
    string reverseVowels(string s) {
        int l=0,r=s.length()-1;
        while(l<r){
            if(!isVowel(s[l]))l++;
            else if(!isVowel(s[r]))r--;
            else swap(s[l++],s[r--]);
        }
        return s;
    }
};