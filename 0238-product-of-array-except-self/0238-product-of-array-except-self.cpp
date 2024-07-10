// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>res;
        int pdt=1;
        for(auto i=nums.begin();i!=nums.end();i++){
            res.push_back(pdt);
            pdt*=*i;
        }
        pdt=1;
        auto  j=res.rbegin();
        for(auto i=nums.rbegin();i!=nums.rend()&&j!=res.rend();i++,j++){
            *j*=pdt;
            pdt*=*i;
        }
        return res;
    }
};