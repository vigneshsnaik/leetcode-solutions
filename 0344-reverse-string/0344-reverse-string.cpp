// https://leetcode.com/problems/reverse-string

class Solution {
public:
    void reverseString(vector<char>& s) {
        auto i=s.begin();
        auto j=s.end()-1;
        while(i<j){
            char c=*i;
            *i++=*j;
            *j--=c;
        }
    }
};