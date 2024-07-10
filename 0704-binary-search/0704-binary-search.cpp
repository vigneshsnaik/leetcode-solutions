// https://leetcode.com/problems/binary-search

class Solution {
public:
    int search(vector<int>& nums, int target, int l=0, int h=INT_MIN) {
        if(nums.size()==1)return nums[0]==target?0:-1;
        if(h==INT_MIN)h=nums.size()-1;
        if(l>h)return -1;
        int mid=(l+h)/2;
        cout<<l<<" "<<h<<endl;
        if(nums[mid]>target)return search(nums,target,l,mid-1);
        if(nums[mid]<target)return search(nums,target,mid+1,h);
        return mid;
    }
};