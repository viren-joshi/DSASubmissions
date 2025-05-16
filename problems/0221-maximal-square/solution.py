class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        ans = 0
        dp = [[0] * len(matrix[0]) for _ in range(len(matrix))]
        for j in range(len(matrix[0])):
            dp[0][j] = int(matrix[0][j])
            ans = max(ans, dp[0][j])
        for i in range(1,len(matrix)):
            dp[i][0] = int(matrix[i][0])
            ans = max(ans, dp[i][0])
        print(dp)
        for rowInd, row in enumerate(matrix):
            if(rowInd == 0): 
                continue
            for colInd, column in enumerate(row):
                if(colInd == 0): 
                    continue
                if column == "1":
                    dp[rowInd][colInd] = min(dp[rowInd - 1][colInd], dp[rowInd][colInd - 1], dp[rowInd - 1][colInd - 1]) + 1
                    ans = max(ans, dp[rowInd][colInd])
        print(dp)
        return ans*ans
