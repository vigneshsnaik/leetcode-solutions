class Solution {
public:
    int minimumPushes(string word) {
        vector<int> count(26);
        for (char c : word) {
            count[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            cout << (char)(i + 'a' )<< " " << count[i]<<endl;
        }
        int res = 0;
        sort(count.rbegin(), count.rend());
        for (int i = 0; i < 26; i++) {
            res += count[i] * (i / 8 + 1);
        }
        return res;
    }
};