// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& height) {
        auto l=height.begin(),r=height.end()-1;
        int l_max=*l,r_max=*r,sum=0;
        while(l<r){
            if(l_max<r_max){
                sum+=l_max-*(l++);
                l_max=l_max>*l?l_max:*l;
            }
            else{
                sum+=r_max-*(r--);
                r_max=r_max>*r?r_max:*r;
            }
        }
        return sum;
    }
};