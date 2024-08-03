class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int cnt[1001];
        for (int i = 0; i < arr.size(); i++) {
            cnt[arr[i]]++;
            cnt[target[i]]--;
        }
        for (int i = 0; i < 1001; i++) {
            if (cnt[i]) {
                return false;
            }
        }
        return true;
    }
};