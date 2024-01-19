class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        for(int i=1;i<rows;i++) {
            matrix[i][0] = matrix[i][0] + min({matrix[i-1][0], matrix[i-1][1]});
            matrix[i][cols-1] = matrix[i][cols-1] + min({matrix[i-1][cols-2], matrix[i-1][cols-1]});
            for(int j=1; j<cols-1; j++) {
                matrix[i][j] = matrix[i][j] + min({matrix[i-1][j-1], matrix[i-1][j], matrix[i-1][j+1]});
            }
        }
        return *min_element(matrix[rows-1].begin(), matrix[rows-1].end());
    }
};