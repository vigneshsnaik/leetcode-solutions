// https://leetcode.com/problems/roman-to-integer

class Solution {
public:
    int val(char ch){
        switch(ch){
            case'I':return 1;
            case'V':return 5;
            case'X':return 10;
            case'L':return 50;
            case'C':return 100;
            case'D':return 500;
            case'M':return 1000;
        }
        return 0;
    }
    int romanToInt(string s){
        int result=0;
        for(int i=0;s[i]!='\0';i++){
            if(val(s[i])>=val(s[i+1]))
                result+=val(s[i]);
            else
                result-=val(s[i]);
        }
        return result;
    }
};