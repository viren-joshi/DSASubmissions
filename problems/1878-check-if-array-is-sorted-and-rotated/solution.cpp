class Solution {
public:
    bool check(vector<int>& nums) {
        bool c = false;
        int i = 1;
        while (i<nums.size()) {
            if (nums[i] < nums[i-1]) {
                if (c) {
                    return false;
                } else {
                    c = true;
                }
            }
            i++;
        }
        return c ? nums[nums.size()-1] <= nums[0] : true;
    }
};
