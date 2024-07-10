// https://leetcode.com/problems/maximum-average-subarray-i

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double avg=(double)accumulate(nums.begin(),nums.begin()+k,0)/k;
        double maxAvg=avg;
        for(int i=k;i<nums.size();i++){
            avg+=(double)(nums[i]-nums[i-k])/k;
            maxAvg=max(avg,maxAvg);
        }
        return maxAvg;
    }
};