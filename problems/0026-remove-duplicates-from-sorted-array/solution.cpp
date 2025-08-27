class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0, right = 0;
        int current;
        while(right < nums.size()) {
            current = nums[right];
            while(right < nums.size() && current == nums[right]) right++;
            nums[left] = current;
            left++;
        }
        return left;
    }
};
