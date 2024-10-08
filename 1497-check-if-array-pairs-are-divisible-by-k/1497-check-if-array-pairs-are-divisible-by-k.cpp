class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> count(k);
        for (int num : arr) {
            int mod = num % k;
            mod = mod >= 0 ? mod : mod + k;
            count[mod]++;
        }
        for (int i : count) {
            cout << i << endl;
        }
        if (count[0] % 2 != 0) {
            return false;
        }
        for (int i = 1; i <= k / 2; i++) {
            if (count[i] != count[k - i]) {
                return false;
            }
        }
        return true;
    }
};