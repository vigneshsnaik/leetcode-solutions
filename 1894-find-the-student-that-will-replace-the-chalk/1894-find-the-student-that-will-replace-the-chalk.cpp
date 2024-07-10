// https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long sum = 0;
        for (int num : chalk) {
            sum += num;
        }
        k %= sum;
        for (int i = 0; i < chalk.size(); i++) {
            if (k < chalk[i])
                return i;
            k -= chalk[i];
        }
        return chalk.size() - 1;
    }
};