// https://leetcode.com/problems/harshad-number

class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int xCpy=x,sum=0;
        while(x) {
            sum+=x%10;
            x/=10; 
        }
        return xCpy%sum?-1:sum;
    }
};