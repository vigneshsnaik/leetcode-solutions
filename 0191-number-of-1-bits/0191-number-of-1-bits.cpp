class Solution {
public:
    int hammingWeight(int n) {
        int res=0;
        while(n){
            res+=1&n;
            n>>=1;
        }
        return res;
    }
};