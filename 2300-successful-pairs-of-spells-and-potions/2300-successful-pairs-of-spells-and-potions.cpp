// https://leetcode.com/problems/successful-pairs-of-spells-and-potions

class Solution {
public:
    vector<int> successfulPairs(vector<int> spells, vector<int>& potions, long long success) {
        int m=potions.size(),n=spells.size();
        sort(potions.rbegin(),potions.rend());
        vector<int>res;
        for(int spell:spells){
            int left=0,right=m-1;
            while(left<=right){
                int mid=left+(right-left)/2;
                if((long long)potions[mid]*spell>=success)left=mid+1;
                else right=mid-1;
            }
            res.push_back(left);
        }
        return res;
    }
};