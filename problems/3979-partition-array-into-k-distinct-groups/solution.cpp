class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        if(nums.size()%k != 0) return false;
        map<int,int> freq;
        for(auto i: nums) {
            freq[i]++;
        }
        int groups = nums.size()/k;
        for(auto i: freq) {
            if(i.second > groups) return false;
        }
        return true;
    }
};
