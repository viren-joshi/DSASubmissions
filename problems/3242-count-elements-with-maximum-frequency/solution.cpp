class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxFreq = INT_MIN;
        map<int,int> freq;
        for(auto num: nums) {
            freq[num]++;
            maxFreq = max(freq[num], maxFreq);
        }
        int ans = 0;
        for(auto val: freq) {
            if(val.second == maxFreq) ans+=val.second;
        }
        return ans;
    }
};
