// https://leetcode.com/problems/maximum-number-of-balloons

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int B=0,A=0,L=0,O=0,N=0;
        for(char c:text){
            switch(c){
                case 'b':B++;
                break;
                case 'a':A++;
                break;
                case 'l':L++;
                break;
                case 'o':O++;
                break;
                case 'n':N++;
                break;
            }
        }
        return min({B,A,L/2,O/2,N});
    }
};