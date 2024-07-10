// https://leetcode.com/problems/pascals-triangle-ii

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0)return{1};
        else if(rowIndex==1)return{1,1};
        else {
            vector<int>prevRow=getRow(rowIndex-1);
            vector<int>res(rowIndex+1,1);
            for(int i=1;i<rowIndex;i++)res[i]=prevRow[i-1]+prevRow[i];
            return res;
        }
    }
};