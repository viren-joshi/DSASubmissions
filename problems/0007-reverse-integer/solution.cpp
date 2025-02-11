class Solution {
public:
    int reverse(int x) {
        long c = 0;
        while(x != 0) {
            c = ((c * 10) + x%10);
            x/=10;
        }
        if(c < INT_MIN || c > INT_MAX) return 0;
        return (int) c;
    }
};
