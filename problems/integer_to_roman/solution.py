class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        # lst = {"I":1,"V":5,"X":10,"L":50,"C":100,"D":500,"M":1000}
        lst = {1:["I"],5:["V","I"],10:["X","I"],50:["L","X"],100:["C","X"],500:["D","C"],1000:["M","C"]}
        # l = [1,2,3,]
        # i=10^^(len(str(num))-1)
        i=pow(10,(len(str(num)) - 1))
        ans = ""
        for s in str(num):
            j = int(s)*i
            if(j==0):
                pass
            elif (j in lst.keys()):
                ans+=lst[j][0]
            elif (j+i in lst.keys()):
                ans+=lst[j+i][1]
                ans+=lst[j+i][0]
            elif (int(s) > 5):
                temp = 5*i
                ans+=lst[temp][0]
                while j > temp:
                    ans+=lst[temp][1]
                    j-=i
            else:
                for k in range(int(s)):
                    ans+=lst[i][0]
            i/=10
        return ans