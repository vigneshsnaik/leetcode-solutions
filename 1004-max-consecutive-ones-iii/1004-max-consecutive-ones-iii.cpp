// https://leetcode.com/problems/max-consecutive-ones-iii

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,res=0;
        while(r<nums.size()){
            if(nums[r]){
                r++;
            }
            else if(k){
                r++,k--;
            }
            else if(nums[l]){
                l++;
            }
            else{
                l++,k++;
            }
            res=max(res,r-l);
        }
        return res;
    }
};