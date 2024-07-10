// https://leetcode.com/problems/longest-palindrome

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> charFrequency;
        int odd=0;
        for(char ch:s)charFrequency[ch]++;
        for(const auto &pair:charFrequency)if(pair.second%2)odd++;
        return odd?s.length()-odd+1:s.length();
    }
};