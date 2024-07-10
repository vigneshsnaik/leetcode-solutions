// https://leetcode.com/problems/replace-words

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> rootSet(dictionary.begin(), dictionary.end());
        vector<string> words;
        string word;
        for (char c : sentence)
            if (c==' '&&!word.empty()) 
                words.push_back(word), word.clear();
            else
                word += c;
        if (!word.empty())
            words.push_back(word);
        auto findRoot = [&](const string& word) -> string {
            for (int i=1;i<=word.length();++i)
                if(rootSet.find(word.substr(0, i))!=rootSet.end())return word.substr(0, i);
            return word;
        };
        for (string& w : words)
            w=findRoot(w);
        string result;
        for (size_t i = 0; i < words.size(); ++i)
            if (i > 0)result += " ", result += words[i];
            else result += words[i];
        return result;
    }
};
