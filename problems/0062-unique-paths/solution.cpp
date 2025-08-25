class Solution {
public:
    int uniquePaths(int m, int n) {

        /*
        // Brute Force Solution (DP Solution)
        // Time Complexity : O(m*n)
        // Space Complexity: O(m*n)

        if(m==1 || n==1) {
            return 1;
        }
        vector<vector<int>> dp(m, vector<int>(n, 1));

        dp[0][0] = 0;

        for(int i = 1; i<m; i++) {
            for(int j = 1; j<n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
        */

        // Combinatorics Solution
        // Time Complexity: O(m-1)
        // Space Complexity: O(1)

        int spots = m + n - 2;
        int mini = m-1;

        double r = 1;

        for(int i = 1; i<=mini; i++) {
            r = r * (spots-mini+i)/i;
        }

        return (int) r;

    }
};
