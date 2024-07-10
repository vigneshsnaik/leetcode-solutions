// https://leetcode.com/problems/guess-number-higher-or-lower

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n,int l=0) {
        int m=(n-l)/2+l;
        return guess(m)?guess(m)<0?guessNumber(m-1,0):guessNumber(n,m+1):m;
    }
};