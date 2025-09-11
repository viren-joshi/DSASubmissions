class Solution {
public:

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

    string sortVowels(string s) {
        unordered_map<char,int> count;
        string ans, sortedVowel = "AEIOUaeiou";

        for (char c: s) {
            if(isVowel(c)) {
                count[c]++;
            }
        }

        int j = 0;

        for(int i = 0; i < s.size(); i++) {
            if(!isVowel(s[i])) {
                ans+=s[i];
            } else {
                while(count[sortedVowel[j]] == 0) {
                    j++;
                }
                ans+=sortedVowel[j];
                count[sortedVowel[j]]--;
            }
        }

        return ans;
    }
};
