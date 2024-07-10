// https://leetcode.com/problems/asteroid-collision

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>res;
        for(int asteroid:asteroids){
            while(!res.empty()&&res.back()>0&&asteroid<0)
                if(res.back()<-asteroid)res.pop_back();
                else if(res.back()>-asteroid)asteroid=0;
                else{
                    res.pop_back();
                    asteroid = 0;
                }
            if(asteroid!=0)res.push_back(asteroid);
        }
        return res;
    }
};
