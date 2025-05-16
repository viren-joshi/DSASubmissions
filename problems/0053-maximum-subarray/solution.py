class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        globalMaxima = -10000
        localMaxima = 0
        for i in range(len(nums)):
            localMaxima = max(nums[i], localMaxima + nums[i])
            if(localMaxima > globalMaxima):
                globalMaxima = localMaxima
        return globalMaxima

