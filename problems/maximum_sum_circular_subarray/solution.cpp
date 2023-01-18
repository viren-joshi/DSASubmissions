class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int len = nums.size();
        int localMaxima = 0, globalMaxima = INT_MIN, sum=0;
        int localMinima = 0, globalMinima = INT_MAX;
        for(int i=0;i<len;i++){
            localMaxima=max(nums[i],nums[i]+localMaxima);
            localMinima=min(nums[i],nums[i]+localMinima);
            if(localMaxima>globalMaxima)
                globalMaxima=localMaxima;
            if(localMinima<globalMinima)
                globalMinima=localMinima;
            sum+=nums[i];
        }
        if(sum == globalMinima)
            return globalMaxima;
        else 
        return max(globalMaxima,sum-globalMinima);
    }
};