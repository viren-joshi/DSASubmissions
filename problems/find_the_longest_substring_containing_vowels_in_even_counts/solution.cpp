class Solution {
public:
    int findTheLongestSubstring(string s) {
        int mask = 0, maxLength = 0;
        map<int,int> mp;
        mp[0] = -1;

        for(int i=0; i<s.size(); i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                mask^=(1 << ((int) s[i]- 'a'));
            }
            if(mp.count(mask)) {
                maxLength = max(maxLength, (i - mp[mask]));
            } else {
                mp[mask] = i;
            }
        }
        return maxLength;
    }
};