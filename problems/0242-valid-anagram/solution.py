class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if(len(s) != len(t)):
            return False
        dictS = {}
        for i in s:
            dictS[i] = dictS.get(i,0) + 1
        for i in t:
            if(not dictS.get(i)):
                return False
            dictS[i]-=1
        for key,val in dictS.items():
            if(val != 0):
                return False
        return True
        
        
