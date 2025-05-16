class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:

        inds = {}
        for index,element in enumerate(nums):
            inds[element] = index
        for key in range(len(nums)):
            diff = target - nums[key]
            if(inds.get(diff) and inds.get(diff) != key):
                return [key, inds[diff]]

        
