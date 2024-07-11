class Solution {
public:
    string word(int num) {
        if (num >= 1000000000) {
            return word(num / 1000000000) + " Billion" +
                   (num % 1000000000 ? " " : "") + word(num % 1000000000);
        } else if (num >= 1000000) {
            return word(num / 1000000) + " Million" +
                   (num % 1000000 ? " " : "") + word(num % 1000000);
        } else if (num >= 1000) {
            return word(num / 1000) + " Thousand" + (num % 1000 ? " " : "") +
                   word(num % 1000);
        } else if (num >= 100) {
            return word(num / 100) + " Hundred" + (num % 100 ? " " : "") +
                   word(num % 100);
        } else if (num >= 20) {
            vector<string> tens = {"",       "Ten",   "Twenty", "Thirty",
                                   "Forty",  "Fifty", "Sixty",  "Seventy",
                                   "Eighty", "Ninety"};
            vector<string> ones = {"",     "One", "Two",   "Three", "Four",
                                   "Five", "Six", "Seven", "Eight", "Nine"};
            return tens[num / 10] + (num % 10 ? " " : "") + ones[num % 10];
        } else {
            vector<string> ones = {
                "",        "One",     "Two",       "Three",    "Four",
                "Five",    "Six",     "Seven",     "Eight",    "Nine",
                "Ten",     "Eleven",  "Twelve",    "Thirteen", "Fourteen",
                "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
            return ones[num];
        }
    }
    string numberToWords(int num) { return num ? word(num) : "Zero"; }
};