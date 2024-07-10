// https://leetcode.com/problems/string-to-integer-atoi

class Solution {
public:
    int myAtoi(string s) {
        short flag=0;
        long res=0;
        char temp='\0';
        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])){
                if(res>INT_MAX||res<INT_MIN) break;
                res=res*10+(s[i]-'0');
                flag=1;
            }
            else if(s[i]==' '&&!flag) continue;
            else if((s[i]=='+'||s[i]=='-')&&!temp&&!flag){
                temp=s[i];
                flag=1;
            }
            else break;
        }
        if(temp=='-') res*=-1;
        if(res>INT_MAX) return INT_MAX;
        if(res<INT_MIN) return INT_MIN;
        return res;
    }
};