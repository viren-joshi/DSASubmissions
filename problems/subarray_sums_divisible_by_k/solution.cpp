class Solution {
public:

    void updateMap(map<int,int>& ans, int remainder) {
        if(ans.find(remainder) != ans.end()) {
                ans[remainder]++;
        } else {
            ans[remainder] = 1;
        }
    }

    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> ans;
        int count=0;
        for (int i=0; i<nums.size();i++) {
            if(i > 0) nums[i]+=nums[i-1];
            int current_remainder = (nums[i] % k + k) % k;
            updateMap(ans,current_remainder);
        }
        if(ans.find(0) != ans.end()) {
            count = ans[0];
        }
        for (auto itr=ans.begin();itr != ans.end(); ++itr) {
            count += (itr->second) * (itr->second - 1) / 2;
        }
        return count;
    }
};