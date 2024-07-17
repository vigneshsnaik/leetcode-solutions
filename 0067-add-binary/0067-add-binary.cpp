class Solution {
public:
    string addBinary(string a, string b) {
        int sum,carry=0,ai=a.length()-1,bi=b.length()-1;
        string res="";
        while(ai>=0||bi>=0||carry){
            sum=(ai>=0?a[ai--]:'0')+(bi>=0?b[bi--]:'0')-2*'0'+carry;
            res=to_string(sum%2)+res;
            carry=sum/2;
        }
        return res;
    }
};