// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length

class Solution {
public:
    int isVowel(char c){
        return(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')?1:0;
    }
    int maxVowels(string s, int k) {
        int vowel=accumulate(s.begin(),s.begin()+k,0,[this](int sum, char c){return sum+isVowel(c);});
        int maxVowel=vowel;
        for(int i=k;i<s.length();i++){
            vowel+=isVowel(s[i])-isVowel(s[i-k]);
            maxVowel=max(vowel,maxVowel);
        }
        return maxVowel;
    }
};