// https://leetcode.com/problems/max-number-of-k-sum-pairs

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int res=0;
        auto l=nums.begin(),r=nums.end()-1;
        while(l<r){
            int sum=*l+*r;
            if(sum>k)r--;
            else if(sum<k)l++;
            else *l++,*r--,res++;
        }
        return res;
    }
};