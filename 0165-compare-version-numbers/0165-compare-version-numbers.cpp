// https://leetcode.com/problems/compare-version-numbers

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,j=0;
        while (i<version1.size()||j<version2.size()){
            int num1=0,num2=0;
            while(i<version1.size()&&version1[i]!='.')num1=num1*10+(version1[i++]-'0');
            while(j<version2.size()&&version2[j]!='.')num2=num2*10+(version2[j++]-'0');
            if (num1!=num2)return num1>num2?1:-1;
            i++,j++;
        }
        return 0;
    }
};