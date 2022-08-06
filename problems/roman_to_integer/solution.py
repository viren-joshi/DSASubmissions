class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        # map_count = {'I':None, 'V':None,'X':None,'L':None,}
        value = 0
        i=0
        l=len(s)
        # for i in range(len(s)):
        while i<l:
            # print("S -",s[i], " I -",i)
            if(s[i]=='I'):
                if(i+1 < l):
                    if(s[i+1]=='V'):
                        value+=4
                        i+=2
                    elif(s[i+1]=='X'):
                        value+=9
                        i+=2
                    # i+=2
                    else:
                        value+=1
                        i+=1
                else:
                    value+=1
                    i+=1
            elif(s[i]=='V'):
                value+=5
                i+=1
            elif(s[i]=='X'):
                if(i+1 < l):
                    if(s[i+1]=='L'):
                        value+=40
                        i+=2
                    elif(s[i+1]=='C'):
                        value+=90
                        i+=2
                    else:
                        value+=10
                        i+=1
                else:
                    value+=10
                    i+=1
            elif(s[i]=='L'):
                value+=50
                i+=1
            elif(s[i]=='C'):
                if(i+1 < l):
                    if(s[i+1]=='D'):
                        value+=400
                        i+=2
                    elif(s[i+1]=='M'):
                        value+=900
                        i+=2
                    else:
                        value+=100
                        i+=1
                else:
                    value+=100
                    i+=1
            elif(s[i]=='D'):
                value+=500
                i+=1
            else:
                value+=1000
                i+=1
        return value    
                    
