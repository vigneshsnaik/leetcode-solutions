class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int n = arr.size();
        vector<int> ones;
        for (int i = 0; i < n; i++) {
            if (arr[i])
                ones.push_back(i);
        }
        int countOnes = ones.size();
        if (countOnes % 3)
            return {-1, -1};
        if (countOnes == 0)
            return {0, static_cast<int>(arr.size() - 1)};
        int i = ones[0], j = ones[countOnes / 3], k = ones[countOnes * 2 / 3];
        while (k < n and arr[i] == arr[k] and arr[j] == arr[k])
            i++, j++, k++;
        if (k == n)
            return { i - 1, j };
        return {-1, -1};
    }
};