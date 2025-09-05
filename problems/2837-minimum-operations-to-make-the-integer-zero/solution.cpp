class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        long long temp = 1;
        int ans = 1;
        while(ans<=60) {
            temp = num1- 1LL * num2 * ans;
            if(temp < ans) return -1;
            if(ans >= __builtin_popcountll(temp)) return ans;
            ans++;
        }
        return -1;
    }
};
