// https://leetcode.com/problems/intersection-of-two-arrays-ii

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> m1(1001), m2(1001), res;
        for (int n : nums1)
            m1[n]++;
        for (int n : nums2)
            m2[n]++;
        for (int i = 0; i < 1001; i++) {
            int t = min(m1[i], m2[i]);
            while (t--)
                res.push_back(i);
        }
        return res;
    }
};