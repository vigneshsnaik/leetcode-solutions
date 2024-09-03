class Solution {
public:
    int getLucky(string s, int k) {
        int res = 0;
        for (char c : s) {
            res += c < 'j'   ? c - 'a' + 1
                         : c < 't' ? c - 'a' - 8
                                   : c - 'a' - 17;
        }
        cout<<res;
        int num = res;
        while (--k) {
            int sum = 0;
            while (num) {
                sum += (num % 10);
                num /= 10;
            }
            res = sum;
        }
        return res;
    }
};