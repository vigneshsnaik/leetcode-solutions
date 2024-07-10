// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto i=nums.begin(),j=nums.begin(),k=nums.begin();
        while (j!=nums.end()){
            if(*i==*j){
                j++;
            }
            else{
                i=j;
                *(++k)=*j;
            }
        }
        return k-nums.begin()+1;
    }
};