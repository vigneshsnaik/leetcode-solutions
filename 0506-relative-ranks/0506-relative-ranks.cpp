// https://leetcode.com/problems/relative-ranks

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> tmp=score;
        sort(tmp.rbegin(),tmp.rend());
        unordered_map<int,string>rankMap;
        rankMap[tmp[0]]="Gold Medal";
        if(tmp.size()>1)rankMap[tmp[1]]="Silver Medal";
        if(tmp.size()>2)rankMap[tmp[2]]="Bronze Medal";
        for (int i=3;i<tmp.size();++i)rankMap[tmp[i]]=to_string(i + 1);
        vector<string> answer(score.size());
        for (int i=0;i<score.size();++i)answer[i]=rankMap[score[i]];
        return answer;
    }
};