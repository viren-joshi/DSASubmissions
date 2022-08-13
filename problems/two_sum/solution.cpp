class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.size()==2) return vector<int> {0,1};
        std::vector<int>::iterator i = nums.end();
        // sort(nums.begin(),nums.end());
        for (std::vector<int>::iterator itr=nums.begin();itr!=nums.end();itr++){
            i = find(itr+1,nums.end(),target-*itr);
            // cout<<*itr<<" "<<*i;
            if(i!=nums.end() && i!=itr){
                return vector<int>{int(itr-nums.begin()),int(i-nums.begin())};
            }
        }
        return vector<int>{0,0};
    }
};