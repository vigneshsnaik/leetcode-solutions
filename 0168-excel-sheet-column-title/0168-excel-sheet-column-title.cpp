class Solution {
public:
    string convertToTitle(int columnNumber) {
        return columnNumber ? convertToTitle(--columnNumber / 26) +
                                  (char)('A' + columnNumber % 26)
                            : "";
    }
};