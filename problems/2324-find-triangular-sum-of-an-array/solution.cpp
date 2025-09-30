class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int temp;
        for(int i = 0; i<nums.size(); i++) {
            temp = nums[0];
            for(int j = 1; j<= nums.size() - i - 1; j++) {
                nums[j-1] = (temp + nums[j]) % 10;
                temp = nums[j];
            }
        }
        return nums[0];
    }
};
