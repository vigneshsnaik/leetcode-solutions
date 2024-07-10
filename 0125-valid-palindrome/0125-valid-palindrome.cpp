// https://leetcode.com/problems/valid-palindrome

class Solution {
public:
    bool isPalindrome(string s) {
        int l=0,r=s.length();
        while(l<r){
            if(!isalnum(s[r]))r--;
            else if(!isalnum(s[l]))l++;
            else{
                if(tolower(s[l])!=tolower(s[r]))return false;
                l++;
                r--;
            }
        }
        return true;
    }
};