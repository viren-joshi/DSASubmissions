class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";
        string s;
        if(numerator < 0 ^ denominator < 0) s += "-";
        long long num = abs((long long)numerator);
        long long den = abs((long long) denominator);
        s += to_string(num / den);
        long long rem = num % den;
        if(rem == 0) return s;

        s += ".";

        map<long long, int> map;
        while(rem != 0) {
            if(map.count(rem)) {
                s.insert(map[rem], "(");
                s += ")";
                break;
            }
            map[rem] = s.size();
            rem *= 10;
            s += to_string(rem/den);
            rem %= den;
        }
        return s;
    }
};
