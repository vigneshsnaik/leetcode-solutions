// https://leetcode.com/problems/string-compression

class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int index=0,i=0;        
        while(i<n) {
            char current_char=chars[i];
            int count=0;
            while(i<n&&chars[i]==current_char)
                count++,i++;
            chars[index++]=current_char;
            string cnt=to_string(count);
            if(cnt!="1")
                for (char c:cnt)
                    chars[index++] = c;
        }
        chars.resize(index);        
        return chars.size();
    }
};
