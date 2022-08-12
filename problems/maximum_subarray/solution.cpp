class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int localMaxima=0;
        int globalMaxima=INT_MIN;
        for(int i=0;i<size;i++){
            localMaxima=max(nums[i],nums[i]+localMaxima);
            if(localMaxima>globalMaxima)
                globalMaxima=localMaxima;
        }
        return globalMaxima;
    }
};