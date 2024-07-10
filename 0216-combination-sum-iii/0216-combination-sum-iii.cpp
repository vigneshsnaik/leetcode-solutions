// https://leetcode.com/problems/combination-sum-iii

class Solution {
public:
    vector<vector<int>>res;
    void combinations(vector<int>combination,int k,int n){
        if(!k&&!n){
            res.push_back(combination);
            return;
        }
        if(k){
            for(int i=combination.empty()?1:combination.back()+1;i<=9;i++){
                if(n<i)break;
                combination.push_back(i);
                combinations(combination,k-1,n-i);
                combination.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n>(k*(19-k))/2||n<(k*(k+1))/2)return {};
        combinations({},k,n);
        return res;
    }
};