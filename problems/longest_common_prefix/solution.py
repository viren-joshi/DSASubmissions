class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        string=""
        strs.sort(key=len)
        for s in enumerate(strs[0]):
            for i in range(len(strs)):
                if(s[1] not in strs[i][s[0]]):
                    return string
            string+=s[1]
        return string
                    