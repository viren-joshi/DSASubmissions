class Solution {
public:

    bool doesAliceWin(string s) {
        if(s.size() == 0) return false;
        for(char c: s) {
            if(c =='a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        }
        return false;
    }
};
