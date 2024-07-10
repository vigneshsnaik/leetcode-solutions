// https://leetcode.com/problems/sort-colors

class Solution {
public:
    void sortColors(vector<int>& nums) {
        auto p1=nums.begin(),p2=nums.begin(),p3=nums.end()-1;
        while(p2<=p3){
            if(*p2==0)
                swap(*p1++,*p2++);
            else if(*p2==1)
                p2++;
            else
                swap(*p2,*p3--);
        }
    }
};