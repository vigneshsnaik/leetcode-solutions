// https://leetcode.com/problems/relative-sort-array

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> val;
        int i=1000;
        for(int num:arr2)
            val[num]=i--;
        sort(arr1.begin(),arr1.end(),[&val](int a, int b){return val[a]!=val[b]?val[a]>val[b]:a<b;});
        return arr1;
    }
};