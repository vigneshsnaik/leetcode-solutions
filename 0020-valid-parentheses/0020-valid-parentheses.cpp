// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<char> t;
        for(int i = 0; i < s.length(); i++) {
            
            if(s[i] == ')') {
                if(t.empty() || t.top() != '(') {
                    return false;
                }
                t.pop();
            } else if(s[i] == ']') {
                if(t.empty() || t.top() != '[') {
                    return false;
                }
                t.pop();
            } else if(s[i] == '}') {
                if(t.empty() || t.top() != '{') {
                    return false;
                }
                t.pop();
            }
            else{
                t.push(s[i]);
            } 
        }
        return t.empty();
    }
};