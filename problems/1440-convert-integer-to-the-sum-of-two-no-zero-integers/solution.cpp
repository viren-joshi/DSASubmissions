class Solution {
public:

    bool checkZeroes(int n) {
        while(n) {
            if(n%10 == 0) return false;
            n/=10;
        }
        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        for(int i=1; i<=n/2;i++) {
            if(checkZeroes(i) && checkZeroes(n-i)) return {i,n-i};
        }
        return {0};
    }
};
