class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for x in enumerate(nums):
            if target-x[1] in nums[x[0]+1:]:
                return[x[0],nums.index(target-x[1],x[0]+1)]
            
        