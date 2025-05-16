class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        maxLen = 0
        subStr = set()
        l = 0
        for right in range(len(s)):
            while s[right] in subStr:
                subStr.remove(s[l])
                l+=1
            subStr.add(s[right])
            maxLen = max(maxLen, (right - l + 1))
        return maxLen
