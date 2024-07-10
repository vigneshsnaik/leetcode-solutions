// https://leetcode.com/problems/can-place-flowers

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i=0;
        while(i<flowerbed.size()&&n){
            if(!flowerbed[i]&&(i==0||!flowerbed[i-1])&&(i==flowerbed.size()-1||!flowerbed[i+1])){
                flowerbed[i]=1;
                n--;
            }
            i++;
        }
        return !n;
    }
};