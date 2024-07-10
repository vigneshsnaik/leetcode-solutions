// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=0,r=0,res=0,k=1;
        while(r<nums.size()){
            if(nums[r])r++;
            else if(k)r++,k--;
            else if(nums[l])l++;
            else l++,k++;
            res=max(res,r-l-1);
        }
        return res;    
    }
};