class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string word;
        stringstream ss(sentence);
        int i = 1;
        while (ss >> word) {
            if (searchWord == word.substr(0, searchWord.size())) {
                return i;
            }
            i++;
        }
        return -1;
    }
};