class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> data;
        for(int i = 0; i<nums.size(); i++) {
            data[nums[i]] = i;
        }
        for(int i=0; i<nums.size(); i++) {
            int temp = target-nums[i];
            if(data.contains(temp) && data[temp] != i) {
                return {i , data[temp]};
            }
        }
        return {0,1};
    }
};
