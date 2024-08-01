class Solution {
public:
    int characterReplacement(string s, int k) {
        int len = s.length();
        int count[26];
        int start = 0, maxCount = 0, maxLength = 0;
        for (int end = 0; end < len; end++) {
            maxCount = max(maxCount, ++count[s[end] - 'A']);
            while (end - start + 1 - maxCount > k) {
                count[s[start] - 'A']--;
                start++;
            }
            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
    }
};