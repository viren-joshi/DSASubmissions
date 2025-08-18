class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int temp = nums[0];
        for(int i = 1; i<nums.size(); i++) {
            temp = temp^nums[i];
        }
        return temp;
    }
};
