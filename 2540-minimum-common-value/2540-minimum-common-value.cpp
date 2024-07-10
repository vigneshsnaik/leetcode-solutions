// https://leetcode.com/problems/minimum-common-value

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        auto i1=nums1.begin(),i2=nums2.begin();
        while(i1!=nums1.end()&&i2!=nums2.end()){
            if(*i1<*i2)
                i1++;
            else if(*i1>*i2)
                i2++;
            else
                return *i1; 
        }
        return -1;
    }
};