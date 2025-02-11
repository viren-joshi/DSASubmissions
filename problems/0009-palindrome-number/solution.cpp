class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int num = s.size();
        for(int i=0; i<num/2; i++) {
            if(s[i] != s[num-i-1]) {
                return false;
            }
        }
        return true;
    }
};
