// https://leetcode.com/problems/make-the-string-great

class Solution {
public:
    string makeGood(string s) {
        stack <char>st;
        string res;
        for(int i=0;i<s.length();i++)
            if(st.empty())st.push(s[i]);
            else if(abs(st.top()-s[i])==32)st.pop();
            else st.push(s[i]);
        while(!st.empty()){
            res=st.top()+res;
            st.pop();
        }
        return res;
    }
};