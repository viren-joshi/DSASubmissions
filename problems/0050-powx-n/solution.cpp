class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long temp = abs((long long)n);
        while(temp>0) {
            if(temp%2 == 0) {
                x = x*x;
                temp = temp / 2;
            } else {
                ans = ans * x;
                temp = temp - 1;
            }
            
        }
        return n<0 ? (double)1/ans : ans;
    }
};
