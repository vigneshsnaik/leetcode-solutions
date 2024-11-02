class Solution {
public:
    bool isCircularSentence(string sentence) {
        if (sentence[0] != sentence.back()) {
            return false;
        }
        for (int i = 0; i < sentence.length(); i++) {
            if (sentence[i] == ' ' and
                tolower(sentence[i + 1]) != tolower(sentence[i - 1])) {
                return false;
            }
        }
        return true;
    }
};