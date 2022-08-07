class Solution(object):
    def greatestLetter(self, s):
        """
        :type s: str
        :rtype: str
        """
        s = sorted(set(s),reverse=True)
        print(s)
        s = [ord(x) for x in s]
        print(s)
        result=""
        for i in s:
            if(i<96):
                break
            elif (i-32) in s :
                if len(result)==0 or ((i-32) > ord(result)): 
                    result=chr(i-32)
        return result;