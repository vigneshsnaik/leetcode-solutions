// https://leetcode.com/problems/k-closest-points-to-origin

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](const vector<int>&a, const vector<int>&b) {
            return a[0]*a[0]+a[1]*a[1]>b[0]*b[0]+b[1]*b[1];
        };

        priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)> pq(cmp);
        for(auto point:points)
            pq.push(point);
        vector<vector<int>>res;
        while(k--){
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};