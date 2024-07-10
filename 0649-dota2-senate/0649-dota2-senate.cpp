// https://leetcode.com/problems/dota2-senate

#define R 'R'
#define D 'D'
#define O 'O'
class Solution {
public:
    string predictPartyVictory(string s) {
        int n=s.size();
        int r=count(s.begin(),s.end(),R);
        int d=count(s.begin(),s.end(),D);
        int i=0;
        while(r&&d){
            if(s[i]==R){
                int idx=i;
                while(s[idx]!=D){
                    idx=(idx+1)%n;
                }
                s[idx]=O;
                d--;
            }
            else if(s[i]==D){
                int idx=i;
                while(s[idx]!=R){
                    idx=(idx+1)%n;
                }
                s[idx]=O;
                r--;
            }
            i=(i+1)%n;
        }
        return r?"Radiant":"Dire";
    }
};