class Solution {
public:

    bool isVowel(char c) {
        return c =='a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    bool doesAliceWin(string s) {
        if(s.size() == 0) return false;
        int countVowels = 0;
        for(char c: s) {
            if(isVowel(c)) return true;
        }
        return false;
    }
};
