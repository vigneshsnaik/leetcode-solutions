// https://leetcode.com/problems/search-insert-position

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int high=nums.size(),low=0,mid;
         if(high==0){
            return 0;
        }
        if(high==1){
            if(nums[0]>=target){
                return 0;
            }
            if(nums[0]<target){
                return 1;
            }
        }
        high--;
        while(high>low){
            mid=(high+low+2)/2;
            if(nums[mid]>target)
                high=mid-1;
            else if(nums[mid]<target)
                low=mid+1;
            else
                return mid;
        }
        if(nums[high]<target)
            return high+1;
        return high;
    }
};