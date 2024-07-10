// https://leetcode.com/problems/reverse-prefix-of-word

class Solution {
public:
    string reversePrefix(string word, char ch) {
        reverse(word.begin(),word.begin()+word.find(ch)+1);
        return word;
    }
};