class Solution {
public:
    int maxDifference(string s) {
        map<int,int> freq;
        for(auto i: s) {
            int num = i - '0';
            freq[num]++;
        }
        int maxOdd = 0, minEven = 101;
        for(auto i=freq.begin();i!=freq.end(); ++i) {
            if(i->second%2==0) {
                minEven = min(i->second, minEven);
            } else {
                maxOdd = max(maxOdd, i->second);
            }
        }
        return maxOdd - minEven;
    }
};
