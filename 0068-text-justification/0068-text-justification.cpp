// https://leetcode.com/problems/text-justification

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>res;
        int k=0;
        while(k<words.size()){
            int strlength=0;
            int i=k;
            while(i<words.size()&&words[i].length()+strlength<=maxWidth){
                strlength+=words[i].length()+1;
                i++;
            }
            int spaceCount=maxWidth-strlength+i-k;
            string tmp;
            if(i>=words.size())
                for(int j=k;j<i;j++){
                    tmp+=words[j];
                    int spaces=tmp.size()<maxWidth?1:0;
                    tmp+=string(spaces,' ');
                    spaceCount-=spaces;
                }
            else
                for(int j=k;j<i;j++){
                    tmp+=words[j];
                    int spaces=(i-j-1)?ceil((float)spaceCount/(i-j-1)):0;
                    spaceCount-=spaces;
                    tmp+=string(spaces,' ');
                }
            if (spaceCount>0)tmp+=string(spaceCount,' ');
            res.push_back(tmp);
            k=i;
        }
        return res;
    }
};