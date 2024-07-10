// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int MAX=0;
        for(int candy:candies)
            MAX=max(candy,MAX);
        vector<bool>res(candies.size());
        auto i=res.begin();
        for(int candy:candies){
            *i++=candy+extraCandies>=MAX;
        }
        return res;
    }
};