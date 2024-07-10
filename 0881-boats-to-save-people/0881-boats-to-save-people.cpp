// https://leetcode.com/problems/boats-to-save-people

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int l=0,r=people.size()-1;
        while(l<=r)if(people[l]+people[r--]<=limit)l++;
        return people.size()-r-1;
    }
};