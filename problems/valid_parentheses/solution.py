class Solution:
    def isValid(self, s: str) -> bool:
        d = {
            '(' : ')',
            '{' : '}',
            '[' : ']'
        }
        stack = []
        for char in s :
            if char in d.keys() :
                stack.append(char)
            else:
                if stack: # added this for an edge case.. 
                    temp = stack[-1]
                    if(d[temp] == char):
                        # this means that we have found the correct closed parathesis for the
                        # corresponding open parathesis
                        # Hence we pop from the stack here
                        stack.pop()
                    else:
                        return False
                else:
                    return False
        return not stack