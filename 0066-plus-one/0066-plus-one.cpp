// https://leetcode.com/problems/plus-one

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        auto i=digits.rbegin();
        while (carry){
            if(i==digits.rend()){
                digits.insert(digits.begin(), 1);
                break;
            }
            *i=*i==9?0:*i+1;
            carry=*i==0?1:0;
            i++;
        }
        return digits;
    }
};