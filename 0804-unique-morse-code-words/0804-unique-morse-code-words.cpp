class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-",   "-...", "-.-.", "-..",  ".",    "..-.",
                                "--.",  "....", "..",   ".---", "-.-",  ".-..",
                                "--",   "-.",   "---",  ".--.", "--.-", ".-.",
                                "...",  "-",    "..-",  "...-", ".--",  "-..-",
                                "-.--", "--.."};
        set<string> morseCode;
        for (string& word : words) {
            string m;
            for (char& c : word) {
                m += (morse[c - 'a']);
            }
            morseCode.insert(m);
        }
        return morseCode.size();
    }
};