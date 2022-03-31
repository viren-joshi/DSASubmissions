class Solution(object):
    def isRobotBounded(self, instructions):
        position = [0,0]
        dirs = ["N","E","S","W"]
        d = 0
        for ch in instructions:
            if ch == 'G':
                if d == 0:
                    position[0] += 1
                elif d == 2:
                    position[0] -= 1
                elif d == 3:
                    position[1] -= 1
                elif d == 1:
                    position[1] += 1
            elif ch == 'R':
                d = (d-1) % 4
            elif ch == 'L':
                d = (d+1) % 4
        print(position, d)
        if position == [0,0] or not (d == 0) :
            return True
        else:
            return False
                    
        """
        :type instructions: str
        :rtype: bool
        """
        