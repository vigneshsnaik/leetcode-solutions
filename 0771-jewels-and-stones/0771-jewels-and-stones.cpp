// https://leetcode.com/problems/jewels-and-stones

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int map[52],res=0;
        for(char c:jewels)map[c>'Z'?c-'a'+26:c-'A']=1;
        for(char c:stones)if(map[c>'Z'?c-'a'+26:c-'A'])res++;
        return res;
    }
};