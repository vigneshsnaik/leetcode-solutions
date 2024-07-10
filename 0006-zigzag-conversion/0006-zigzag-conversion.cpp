// https://leetcode.com/problems/zigzag-conversion

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1||s.length()<=2)
            return s;
        string res;
        int p=0,q=2*(numRows-1);
        while(p<=q)
        {
            for(int j=0;j<s.length();j+=2*(numRows-1))
            {
                if((j+p)<s.length())
                {
                    if ((p!=q))
                    {
                        res+=string(1,s[j+p]);
                    }
                }
                else
                {
                    break;
                }
                if((j+q)<s.length())
                {
                    if(q!=2*(numRows-1))
                    {
                        res+=string(1,s[j+q]);
                    }
                }
                else
                {
                    break;
                }
            }
            p++;
            q--;
        }
        return res;
    }
};