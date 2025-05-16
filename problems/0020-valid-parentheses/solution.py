class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        d = {
            ')' : '(',
            '}' : '{',
            ']' : '['
        }
        for char in s:
            if char in d.values():
                stack.append(char)
            else:
                if stack and stack[-1] == d[char]:
                    stack.pop()
                else:
                    return False
        return not stack


