class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.size()==2) return vector<int> {0,1};
        auto i = nums.end();
        for (auto itr=nums.begin();itr!=nums.end();itr++){
            i = find(itr+1,nums.end(),target-*itr);
            if(i!=nums.end() && i!=itr){
                return vector<int>{int(itr-nums.begin()),int(i-nums.begin())};
            }
        }
        return vector<int>{0,0};
    }
};