class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        map<char, int> romInt = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int prev = 0;
        for(int i = s.size()-1; i>=0; i--) {
            int t = romInt[s[i]];
            if(((prev == 5 || prev == 10) && t==1) || 
            ((prev == 50 || prev == 100) && t == 10) || ((prev==500 || prev==1000) && t==100)) {
                ans-=t;
            } else {
                ans+=t;
            }
            prev = t;
        }
        return ans;
    }
};
