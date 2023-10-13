class Solution {
    public int[] twoSum(int[] nums, int target) {
        int ans[] = {0,1};
        int temp;
        for (int i=0; i<nums.length; i++) {
            temp = target-nums[i];
            for(int j=i+1; j<nums.length;j++) {
                if(nums[j]==temp) {
                    ans[0] = i;
                    ans[1] = j;
                    return ans;
                }
            }
        }
        return ans;
    }
}