// https://leetcode.com/problems/defanging-an-ip-address

class Solution {
public:
    string defangIPaddr(string address) {
        string res;
        for(int i=0;i<address.length();i++){
            res+=(address[i]=='.'?"[.]":string(1,address[i]));
        }
        return res;
    }
};