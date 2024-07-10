// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int mx=-1;
        for(auto i=arr.rbegin();i!=arr.rend();i++){
            int tmp=*i;
            *i=mx;
            mx=max(mx,tmp);
        }
        return arr;
    }
};