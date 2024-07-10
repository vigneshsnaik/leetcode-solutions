// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        auto l=height.begin();
        auto r=height.end()-1;
        int area=0,maxArea=0;
        while(l<r){
            area=(*l<*r?*l:*r)*(r-l);
            maxArea=(area>maxArea?area:maxArea);
            if(*l<*r) l++;
            else r--;
        }
        return maxArea;
    }
};