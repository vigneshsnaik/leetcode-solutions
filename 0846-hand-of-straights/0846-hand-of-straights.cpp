// https://leetcode.com/problems/hand-of-straights

class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == -1) continue;
            int cnt = 1 , prev = nums[i] + 1;
            for(int j = i + 1 ; j < nums.size() && cnt != k ; j++){
                if(prev == nums[j]) {
                    cnt++;
                    prev++;
                    nums[j] = -1;
                }
            }
            if(cnt != k) return false;
        }
        return true;
    }
};