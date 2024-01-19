class Solution {
public:
    bool isPalindrome(string s) {
        string pali;
        for(char c : s) {
            if(isalpha(c) || isdigit(c)) {
                pali+= (char) tolower(c);
            }
        }
        for(int i=0,j=pali.size()-1;i<pali.size()/2; i++,j--){
            if(pali[i] != pali[j]) {
                return false;
            }
        }
        return true;
    }
};