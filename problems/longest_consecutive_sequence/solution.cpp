class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
        return 0;
        sort(nums.begin(),nums.end());
        int count = 0, tempCount=1;
        for(int i=1; i<nums.size();i++) {
            if(nums[i] == nums[i-1])
                continue;
            if(nums[i] == nums[i-1] + 1) {
                tempCount++;
            } else {
                count = max(count,tempCount);
                tempCount = 1;
            }
        }
        return max(count,tempCount);
    }
};