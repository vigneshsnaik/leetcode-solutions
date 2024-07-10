// https://leetcode.com/problems/remove-element

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto j=nums.begin();
        for (auto i=nums.begin();i!=nums.end();i++){
            if(*i!=val){
                *j=*i; 
                j++;
            }
        }
        return j-nums.begin();
    }
};