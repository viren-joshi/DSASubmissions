class Solution {
public:

    int isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxFreqSum(string s) {
        int vowelFreq = 0, consFreq = 0;
        map<char,int> letters;
        for(char c: s) {
            letters[c]++;
            if(isVowel(c)) {
                vowelFreq = max(vowelFreq, letters[c]);
            } else {
                consFreq = max(consFreq, letters[c]);
            }
        }
        return vowelFreq + consFreq;
    }
};
