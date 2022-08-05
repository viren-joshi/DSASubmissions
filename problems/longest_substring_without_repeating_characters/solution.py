class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        # dic = {}
        count=0
        sub_string = ""
        i=0
        j=0
        for i in range(len(s)):
        # while i<len(s):
            sub_string = ""
            for sub in s[i:]:
                # i+=1
                # print("Substring",sub_string)
                if sub not in sub_string:
                    sub_string+=sub
                    
                else:
                    break
                
            count=max(count,len(sub_string))
            # print("Count:",count)
        # print(sub_string)     
        return count