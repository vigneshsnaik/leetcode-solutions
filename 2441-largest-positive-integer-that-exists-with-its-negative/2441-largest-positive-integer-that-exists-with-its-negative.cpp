// https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        auto i=nums.begin(),j=nums.end()-1;
        while(i<j){
            if(-1*(*i)<*j)j--;
            else if(-1*(*i)>*j)i++;
            else return *j;
        }
        return -1;
    }
};