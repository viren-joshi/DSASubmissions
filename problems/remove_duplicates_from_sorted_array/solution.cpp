class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // int len = nums.size();
        int j=0;
        for (int i=1;i<nums.size();i++){
            if(nums[j]!=nums[i]){
                j++;
                nums[j]=nums[i];
                // prev=nums[i];
            }
        }
        return j+1;
    }
};