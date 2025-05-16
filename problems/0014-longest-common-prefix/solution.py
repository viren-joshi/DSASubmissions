class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        prefix = ""
        strs.sort(key=lambda x: len(x))
        print(strs)

        for i in range(len(strs[0])):
            curr = strs[0][i]
            for s in strs:
                if (curr != s[i]):
                    return prefix
            else:
                prefix += curr
        return prefix
