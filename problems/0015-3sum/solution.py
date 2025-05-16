class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = []
        for i in range(len(nums)):
            if i>0 and nums[i] == nums[i-1]:
                continue
            k = i+1
            j = len(nums) - 1
            while k < j:
                sum = nums[i] + nums[k] + nums[j]
                if sum == 0:
                    ans.append([nums[i], nums[k], nums[j]])
                    while k < j and nums[j] == nums[j-1]:
                        j-=1
                    while k < j and nums[k] == nums[k+1]:
                        k+=1
                    j-=1
                    k+=1
                elif sum > 0:
                    j-=1
                else: k+=1
        return ans
