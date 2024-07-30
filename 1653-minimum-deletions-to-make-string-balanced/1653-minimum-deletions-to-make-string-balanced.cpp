class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> A(n), B(n);
        A[0] = count(s.begin(), s.end(), 'a');
        B[0] = (s[0] == 'b');
        int a = 0, b = 0;
        for (int i = 1; i < n; i++) {
            A[i] = A[i - 1] - (s[i - 1] == 'a');
            B[i] = B[i - 1] + (s[i] == 'b');
        }
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            res = min(res, A[i] + B[i] - 1);
        }
        return res;
    }
};