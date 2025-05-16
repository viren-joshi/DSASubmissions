class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        freq = {}
        for i in t:
            freq[i] = freq.get(i,0) + 1
        for i in s:
            freq[i]-=1
        for key, val in freq.items():
            if(val>0):
                return key
