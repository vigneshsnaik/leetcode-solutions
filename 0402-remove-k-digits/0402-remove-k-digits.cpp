class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.length())return "0";
        int i=0;
        while(i<num.length()-1&&k){
            if(num[i+1]<num[i]){
                num.erase(num.begin()+i);
                k--;
                if(i)i--;
            }
            else i++;
        }
        while (k){
            num.erase(num.begin()+(i--));
            k--;
        }
        while(num[0]=='0')num.erase(num.begin());
        return num.length()?num:"0";
    }
};