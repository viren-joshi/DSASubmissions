class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        row = [0] * len(matrix)
        column = [0] * len(matrix[0])
        for i in enumerate(matrix):
            for j in enumerate(i[1]):
                if(j[1]==0):
                    row[i[0]] = 1
                    column[j[0]] = 1
  
        for i in enumerate(row):
            # if(row[i])
            for j in enumerate(column):
                if(i[1] == 1 or j[1] == 1):
                    matrix[i[0]][j[0]] = 0

        return matrix
        