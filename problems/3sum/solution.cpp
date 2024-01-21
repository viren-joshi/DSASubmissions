class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        sort(nums.begin(),nums.end());
        int j,k,temp,sum;
        for(int i=0; i<nums.size();i++) {
            temp = nums[i];
            j = nums.size()-1;
            k = i+1;
            while(k<j) {
                sum = temp + nums[j] + nums[k];
                if(sum == 0) {
                    // ans.push_back({temp, nums[k], nums[j]});
                    s.insert({temp, nums[k], nums[j]});
                    j--;
                    k++;
                } else if(sum > 0) {
                    j--;
                } else {
                    k++;
                }
            }
        }
        for(auto val : s) {
            ans.push_back(val);
        }
        return ans;
    }
};