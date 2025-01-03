class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<string,int> mpp;
        for(int i=0;i+10 <= s.length();i++){
            mpp[s.substr(i,10)]++;
        }
        for(auto& i:mpp){
            if(i.second > 1){
                res.push_back(i.first);
            }
        }
        return res;
    }
};