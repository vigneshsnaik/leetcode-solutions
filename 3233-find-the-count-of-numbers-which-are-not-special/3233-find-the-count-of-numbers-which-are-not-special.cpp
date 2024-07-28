class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int max = std::sqrt(r) + 1;
        vector<bool> isPrime(max + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= max; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= max; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        unordered_set<int> specialNumbers;
        for (int i = 2; i <= max; ++i) {
            if (isPrime[i]) {
                int specialNumber = i * i;
                if (specialNumber >= l && specialNumber <= r) {
                    specialNumbers.insert(specialNumber);
                }
            }
        }
        int totalCount = r - l + 1;
        int specialCount = 0;
        for (int num : specialNumbers) {
            if (num >= l && num <= r) {
                specialCount++;
            }
        }
        return totalCount - specialCount;
    }
};
